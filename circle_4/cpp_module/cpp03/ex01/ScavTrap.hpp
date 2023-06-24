#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &scavTrap);
  ScavTrap &operator=(const ScavTrap &scavTrap);
  virtual ~ScavTrap();

  /*
  * virtual function
    ! 자식 클래스에서 재정의 해주기 위해 다시 선언
  */
  void attack(const std::string &target);

  void guardGate();
};

#endif
