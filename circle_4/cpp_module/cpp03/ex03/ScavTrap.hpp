#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &scavTrap);
  ScavTrap &operator=(const ScavTrap &scavTrap);
  virtual ~ScavTrap();

  void attack(const std::string &target);

  void guardGate();
};

#endif
