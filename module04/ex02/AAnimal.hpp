#ifndef AAnimal_HPP
# define AAnimal_HPP

#include    <string>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);
        std::string getType() const;
        virtual void makeSound() const = 0; //pure virtual function
};

#endif

//parent's pointer can be declared to a child
//virtual ~Animal() : 부모 포인터로 자식 삭제

//abstract class : class including a pure virtual function.