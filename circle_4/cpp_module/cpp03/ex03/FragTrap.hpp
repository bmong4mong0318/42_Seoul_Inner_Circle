#ifndef FRAGTRAP_H_
#define FRAGTRAP_H_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &fragTrap);
  FragTrap &operator=(const FragTrap &fragTrap);
  virtual ~FragTrap();

  void highFivesGuys();
};

#endif
