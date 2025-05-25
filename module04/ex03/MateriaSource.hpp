#ifndef MateriaSource_HPP
# define MateriaSource_HPP

#include    "IMateriaSource.hpp"
#include    "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *Materias[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif