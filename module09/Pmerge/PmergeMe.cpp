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

struct CompareElements {
    bool operator()(const element* a, const element* b) const {
        return a->valeur < b->valeur;
    }
};


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

template <typename T>
const indPair *find_pending_element(const T &loser, int target)
{
    for (size_t i = 0; i < loser.size(); i++)
    {
        if (loser[i].get_pair_index() == target)
            return &loser[i];
    }
    return NULL;
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

void fordJohnsonSort(std::vector<element*>& elements) {
    int single = 0;
    int n = elements.size();
    if (n < 2) 
        return;
    std::vector<element*> winners;
    for (int i = 0; i + 1 < n; i += 2) {
        if (elements[i]->valeur > elements[i + 1]->valeur)
            std::swap(elements[i], elements[i + 1]);
        elements[i + 1]->add_loser(elements[i]);
        winners.push_back(elements[i + 1]);
    }
    if (n % 2 == 1) // 따로 관리
        single = 1;

    // 3. winners 재귀 정렬
    fordJohnsonSort(winners);

    std::vector<element*> mainChain;
    // 4. main chain 정렬
    element *b1 = winners[0]->loser.back();
    winners[0]->loser.pop_back();
    mainChain.push_back(b1);

    for(size_t i = 0; i < winners.size(); i++)
        mainChain.push_back(winners[i]);
    //5. Jacobsthal 순서로 나머지 losers 삽입
    std::vector<int> order = jacobsthal_order(winners.size() + single);
    for (size_t i = 0; i < order.size(); i++)
    {
        int pendingInd = order[i];
        if (pendingInd == 0)
            continue;
        element* pendingelement = NULL;
        std::vector<element*>::iterator searchEnd = mainChain.end();
        if (pendingInd < (int)winners.size())
        {
            pendingelement = winners[pendingInd]->loser.back();
            winners[pendingInd]->loser.pop_back();
            std::vector<element*>::iterator it = std::find(mainChain.begin(), mainChain.end(), winners[pendingInd]);
            if (it != mainChain.end())
                searchEnd = it;
        }
        else
            pendingelement = elements.back(); // single

        std::vector<element*>::iterator insert_pos = std::lower_bound(mainChain.begin(), searchEnd, pendingelement, CompareElements());
        mainChain.insert(insert_pos, pendingelement);
    }
    elements = mainChain; // 최종 정렬된 mainChain을 elements로 복사
}

void fordJohnsonSort(std::deque<indPair>& pairs) {

    int n = pairs.size();
    if (n < 2) 
        return;

    std::deque<indPair> winners;
    std::deque<indPair> losers;
    int pairInd = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        if (pairs[i].value > pairs[i+1].value)
            std::swap(pairs[i], pairs[i+1]);
        pairs[i].pair_index.push_back(pairInd);
        pairs[i + 1].pair_index.push_back(pairInd);
        losers.push_back(indPair(pairs[i]));
        winners.push_back(indPair(pairs[i + 1]));
        pairInd++;
    }
    if (n % 2 == 1) {
        pairs.back().pair_index.push_back(pairInd);
        losers.push_back(indPair(pairs.back()));
    }
    fordJohnsonSort(winners);
    std::deque<indPair> mainChain;


    for (size_t i = 0; i < winners.size(); i++)
        mainChain.push_back(winners[i]);

    std::vector<int> order = jacobsthal_order(losers.size());
    for (size_t i = 0; i < order.size(); i++)
    {
        int pendingInd = order[i];
        const indPair *pending = &losers.back();
        std::deque<indPair>::iterator searchEnd = mainChain.end();
        if (pendingInd == 0)
        {
            pending = find_pending_element(losers, winners[0].get_pair_index());
            mainChain.push_front(*pending);
            continue;
        }
        if (pendingInd < (int)winners.size())
        {
            int pairIndex = winners[pendingInd].get_pair_index();
            pending = find_pending_element(losers, pairIndex);
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
    for (size_t i = 0; i < mainChain.size(); i++) {
        if (!mainChain[i].pair_index.empty())
            mainChain[i].pair_index.pop_back();
    }
    pairs = mainChain;
}

void PmergeMe::fordJohnsonPair(std::vector<int>& v) {
    std::vector<element> pool;
    pool.reserve(v.size());
    for (size_t i = 0; i < v.size(); i++)
        pool.push_back(element(v[i]));

    std::vector<element*> elements;
    for (size_t i = 0; i < pool.size(); i++)
        elements.push_back(&pool[i]);

    fordJohnsonSort(elements);

    //최종 정렬된 vector<int> 생성
    v.clear();
    for (size_t i = 0; i < elements.size(); ++i) {
        v.push_back(elements[i]->valeur);
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
