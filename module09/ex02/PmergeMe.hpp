#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <vector>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <cstring>

//extern int comp;

struct indPair
{
    int value;
    std::vector<int> pair_index;
    
    indPair(int v) : value(v) {}
    indPair(int v, int p_ind) : value(v) {
        pair_index.push_back(p_ind);
    }
    bool operator<(const indPair &other) const {
        //comp++;
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
