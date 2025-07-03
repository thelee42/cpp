#ifndef Base_HPP
# define Base_HPP

class Base
{
    public:
        virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate();
void identify(Base* p);
void identify(Base& p);

#endif

// empty class
// 1. tag type
// 2. template type

