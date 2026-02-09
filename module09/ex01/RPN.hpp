#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
    private:
        std::stack<int> numbers;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        void pushNumber(int number);
        void applyOperator(const std::string &token);
        int getTop() const;
};

#endif
