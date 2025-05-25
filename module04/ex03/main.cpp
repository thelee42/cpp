
// #include    "AMateria.hpp"
// #include    "Ice.hpp"
// #include    "Cure.hpp"
// #include    "ICharacter.hpp"
// #include    "Character.hpp"
// #include    "IMateriaSource.hpp"
// #include    "MateriaSource.hpp"

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }

// ./Interface | cat -e
// * shoots an ice bolt at bob *$
// * heals bob`s wounds *$

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>


int main()
{
    // MateriaSource 생성 및 학습
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // 캐릭터 생성
    ICharacter* me = new Character("me");

    // Materia 생성 및 장착
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // 또 다른 캐릭터 생성
    ICharacter* bob = new Character("bob");

    // Materia 사용
    me->use(0, *bob);   // ice 사용
    me->use(1, *bob);   // cure 사용

    // 잘못된 index 사용 테스트
    me->use(2, *bob);   // 아무것도 없어야 함
    me->use(3, *bob);   // 아무것도 없어야 함

    // 인벤토리 가득 차면 장착 불가 테스트
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("cure"));   // 4개 다 찼음
    me->equip(src->createMateria("ice"));    // 무시됨

    // 인벤토리 해제 후 다시 사용
    me->unequip(1);                          // cure unequip
    me->equip(src->createMateria("ice"));    // 빈자리 채움

    me->use(1, *bob);                        // ice 사용
    me->use(4, *bob);                        // 없는 슬롯

    // 정리
    delete bob;
    delete me;
    delete src;

    return 0;
}

// ./Interface
// * shoots an ice bolt at bob *
// * heals bob`s wounds *