#ifndef Ice_HPP
#define Ice_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
  Ice();
  Ice(const Ice &ref);
  Ice &operator=(const Ice &ref);
  ~Ice();

  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif // Ice_HPP
