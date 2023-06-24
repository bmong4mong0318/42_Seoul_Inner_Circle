#ifndef Character_HPP
#define Character_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
  private:
    std::string _name;
    AMateria*   _inventory[4];
    int         _floorSize;    
    AMateria*   _floor[10];

  public:
    Character();
    Character(std::string name);
    Character(const Character& ref);
    Character&	operator=(const Character& ref);
    virtual ~Character();

    std::string const &getName();
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    void floor(int idx);
    void cleanFloor();
};

#endif  //Character_HPP
