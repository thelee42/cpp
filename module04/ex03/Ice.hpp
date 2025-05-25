#ifndef Ice_HPP
# define Ice_HPP

#include    "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif