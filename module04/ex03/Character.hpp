#ifndef Character_HPP
# define Character_HPP

#include    "ICharacter.hpp"
#include    "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *Materias[4];
    public:
        Character();
        ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        Character(std::string name);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif