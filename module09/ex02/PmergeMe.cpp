#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vec(), deq() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char **sequence)
{
    for(int i = 1; sequence[i]; i++)
    {
        for(size_t j = 0; j < std::strlen(sequence[i]); j++)
        {
            if (!std::isdigit(sequence[i][j]))
                throw std::runtime_error("Only positive integers are allowed");
        }
        long num = std::atol(sequence[i]); //atoi is not safe -> use strtol to handle MAX/MIN_INT
        if (num > 2147483647)
            throw std::runtime_error("Number out of int range");
        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    vec = other.vec;
    deq = other.deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

void PmergeMe::printVec() const
{
    if (vec.empty())
        return;
    std::cout << "Vector: ";
    for(std::vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); it++)
    {
        if (it != vec.cbegin())
            std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
}

void PmergeMe::printDeq() const
{
    if (deq.empty())
        return;
    std::cout << "Deque: ";
    for(std::deque<int>::const_iterator it = deq.cbegin(); it != deq.cend(); it++)
    {
        if (it != deq.cbegin())
            std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
}

std::vector<int> jacobsthal_order(int n)
{
    std::vector<int> order;
    if (n < 1)
        return order;
    if (n == 1) 
    {
        order.push_back(0);
        return order;
    }
    std::vector<int> j;
    j.push_back(0);
    j.push_back(1);
    while (j.back() < n)
        j.push_back(j.back() + 2 * j[j.size() - 2]); //Jn = J[n - 1] + (2 * J[n - 2])
    int last = 0;
    for (size_t i = 1; i < j.size(); i++)
    {
        int current = std::min(j[i], n);
        for (int k = current; k > last; k--)
            order.push_back(k-1);
        last = current;
    }
    return order;    
}

template <typename T>
const indPair *find_pending_pair(const T &loser, int target)
{
    for (size_t i = 0; i < loser.size(); i++)
    {
        if (loser[i].get_pair_index() == target)
            return &loser[i];
    }
    return NULL;
}

template <typename T>
void splitPairs(T& pairs, T& winners, T& losers) {
    int pairInd = 0;
    for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
        if (pairs[i + 1] < pairs[i])
            std::swap(pairs[i], pairs[i+1]);
        pairs[i].pair_index.push_back(pairInd);
        pairs[i + 1].pair_index.push_back(pairInd);
        losers.push_back(indPair(pairs[i]));
        winners.push_back(indPair(pairs[i + 1]));
        pairInd++;
    }
    if (pairs.size() % 2 == 1) {
        pairs.back().pair_index.push_back(pairInd);
        losers.push_back(indPair(pairs.back()));
    }
}


std::vector<indPair> initMainchain(const std::vector<indPair>& winners, const std::vector<indPair>& losers) {
    std::vector<indPair> mainChain;
    int b1PairIndex = winners[0].get_pair_index();
    const indPair *b1 = find_pending_pair(losers, b1PairIndex);
    mainChain.push_back(*b1);

    for (size_t i = 0; i < winners.size(); i++)
        mainChain.push_back(winners[i]);
    return mainChain;
}


void insertPending(std::vector<indPair>& mainChain, std::vector<indPair>& losers, std::vector<indPair>& winners) {
    std::vector<int> order = jacobsthal_order(losers.size());
    for (size_t i = 0; i < order.size(); i++)
    {
        int pendingInd = order[i];
        if (pendingInd == 0)
            continue;
        const indPair *pending = &losers.back();
        std::vector<indPair>::iterator searchEnd = mainChain.end();
        if (pendingInd < (int)winners.size())
        {
            int pairIndex = winners[pendingInd].get_pair_index();
            pending = find_pending_pair(losers, pairIndex);
            for (std::vector<indPair>::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
                if (it->get_pair_index() == pairIndex) {
                    searchEnd = it;
                    break;
                }
            }    
        }
        std::vector<indPair>::iterator insert_pos = std::lower_bound(mainChain.begin(), searchEnd, *pending);
        mainChain.insert(insert_pos, *pending);
    }
}

void insertPending(std::deque<indPair>& mainChain, std::deque<indPair>& losers, std::deque<indPair>& winners) {
    std::vector<int> order = jacobsthal_order(losers.size());
    for (size_t i = 0; i < order.size(); i++)
    {
        int pendingInd = order[i];
        const indPair *pending = &losers.back();
        std::deque<indPair>::iterator searchEnd = mainChain.end();
        if (pendingInd == 0)
        {
            pending = find_pending_pair(losers, winners[0].get_pair_index());
            mainChain.push_front(*pending);
            continue;
        }
        if (pendingInd < (int)winners.size())
        {
            int pairIndex = winners[pendingInd].get_pair_index();
            pending = find_pending_pair(losers, pairIndex);
            for (std::deque<indPair>::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
                if (it->get_pair_index() == pairIndex) {
                    searchEnd = it;
                    break;
                }
            }
        }
        std::deque<indPair>::iterator insert_pos = std::lower_bound(mainChain.begin(), searchEnd, *pending);
        mainChain.insert(insert_pos, *pending);
    }
}

void fordJohnsonSort(std::vector<indPair>& pairs) {

    int n = pairs.size();
    if (n < 2) 
        return;

    std::vector<indPair> winners;
    std::vector<indPair> losers;
    splitPairs(pairs, winners, losers);

    fordJohnsonSort(winners);

    std::vector<indPair> mainChain = initMainchain(winners, losers);

    insertPending(mainChain, losers, winners);

    for (size_t i = 0; i < mainChain.size(); i++) {
        if (!mainChain[i].pair_index.empty())
            mainChain[i].pair_index.pop_back();
    }
    pairs = mainChain;
}

void fordJohnsonSort(std::deque<indPair>& pairs) {

    int n = pairs.size();
    if (n < 2) 
        return;

    std::deque<indPair> winners;
    std::deque<indPair> losers;
    splitPairs(pairs, winners, losers);

    fordJohnsonSort(winners);

    std::deque<indPair> mainChain;
    for (size_t i = 0; i < winners.size(); i++)
        mainChain.push_back(winners[i]);

    insertPending(mainChain, losers, winners);

    for (size_t i = 0; i < mainChain.size(); i++) {
        if (!mainChain[i].pair_index.empty())
            mainChain[i].pair_index.pop_back();
    }
    pairs = mainChain;
}


void PmergeMe::fordJohnsonPair(std::vector<int>& v) {
    std::vector<indPair> pairs;
    for (size_t i = 0; i < v.size(); i++)
        pairs.push_back(indPair(v[i]));

    fordJohnsonSort(pairs);

    v.clear();
    for (size_t i = 0; i < pairs.size(); ++i) {
        v.push_back(pairs[i].value);
    }
}

void PmergeMe::fordJohnsonPair(std::deque<int>& v) {
    std::deque<indPair> pairs;
    for (size_t i = 0; i < v.size(); i++)
        pairs.push_back(indPair(v[i]));

    fordJohnsonSort(pairs);

    v.clear();
    for (size_t i = 0; i < pairs.size(); ++i) {
        v.push_back(pairs[i].value);
    }
}
