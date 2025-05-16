#ifndef AMateria_HPP
# define AMateria_HPP

#include    "ICharacter.hpp"
#include    <string>

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        ~AMateria();
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        AMateria(std::string const &type);
        std::string const &getType() const;
        virtual AMateria clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif