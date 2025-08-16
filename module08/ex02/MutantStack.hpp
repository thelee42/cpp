#ifndef MutantStack_HPP
# define MutantStack_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {}
        ~MutantStack() {}
        MutantStack(const MutantStack &other) : std::stack<T>(other) {}
        MutantStack &operator=(const MutantStack &other) {
            std::stack<T>::operator=(other);
            return *this;
        }
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}
        const_iterator begin() const {return this->c.begin();}
        const_iterator end() const {return this->c.end();}
        reverse_iterator rbegin() {return this->c.rbegin();}
        reverse_iterator rend() {return this->c.rend();}
        const_reverse_iterator rbegin() const {return this->c.rbegin();}
        const_reverse_iterator rend() const {return this->c.rend();}
};

#endif


/* 
std::stack :
    a Container Adapter(stack, queue, priority_queue...)
    it doesn't contain a data, but another container (vector, deque, list) to store data.
    = a wrapper around a container.
    stack is LIFO (Last In First Out) structure.
    default container is deque. (#include <deque>)

template <class T, class Container = std::deque<T> >
class stack {
protected:
    Container c;   // the underlying container
public:
    typedef typename Container::value_type value_type;
    typedef typename Container::size_type size_type;
    typedef Container container_type;
    // ...
};

making alias :
    typedef typename std::stack<T>::container_type::iterator iterator;

*/