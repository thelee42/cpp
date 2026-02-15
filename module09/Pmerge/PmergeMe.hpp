#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <vector>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <cstring>

//extern int comp;

struct pairs
{
    int valeur;
    std::vector<pairs*> loser;

    pairs(int v) : valeur(v){}
    ~pairs() {}
    void add_loser(pairs *l) {
        loser.push_back(l);
    }
    bool operator<(const pairs &other) const {
        //comp++;
        return valeur < other.valeur;
    }
};

struct indPair
{
    int value;
    std::vector<int> pair_index;
    indPair(int v) : value(v) {}
    indPair(int v, int p_ind) : value(v) {
        pair_index.push_back(p_ind);
    }
    bool operator<(const indPair &other) const {
        return value < other.value;
    }
    int get_pair_index() const {
        if (pair_index.empty())
            return -1;
        return pair_index.back();
    }
};


class PmergeMe
{
    public:
        std::vector<int> vec;
        std::deque<int> deq;
        PmergeMe();
        ~PmergeMe();
        PmergeMe(char **sequence);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void fordJohnsonPair(std::vector<int>& v);
        void fordJohnsonPair(std::deque<int>& v);
 
        void printVec() const;
        void printDeq() const;
};

#endif


/*

- size()
- empty()
- max_size()

- operator[]
- at()
- front()
- back()

- begin()
- end()
- rbegin()
- rend()

- push_back()
- pop_back()
- insert()
- erase()
- clear()
- swap()

**only deque**
- push_front()
- pop_front()

*/