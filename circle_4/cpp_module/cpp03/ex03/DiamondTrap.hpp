#ifndef DIAMONDTRAP_H_
#define DIAMONDTRAP_H_

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
  std::string _name;

public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap &diamondTrap);
  DiamondTrap &operator=(const DiamondTrap &diamondTrap);
  ~DiamondTrap();

  void whoAmI(void);
  void printStatus(void);
};

#endif
