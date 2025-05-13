#ifndef Animal_HPP
# define Animal_HPP

#include    <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        std::string getType() const;
        virtual void makeSound() const;
};

#endif

//parent's pointer can be declared to a child
//virtual ~Animal() : 부모 포인터로 자식 삭제