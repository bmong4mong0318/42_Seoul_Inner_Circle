#ifndef ICharacter_HPP
#define ICharacter_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
public:
  virtual ~ICharacter(){};
  virtual std::string const &getName() = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;
};

#endif // ICharacter_HPP