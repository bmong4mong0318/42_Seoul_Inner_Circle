#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("DiamondTrap_clap_name")
{
  std::cout << "DiamondTrap default constructor is called." << std::endl;
  this->_name = "DiamondTrap";
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name")
{
  std::cout << "DiamondTrap " << name << " is called." << std::endl;
  this->_name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
  std::cout << "DiamondTrap copy constructor is called." << std::endl;
  this->_name = diamondTrap.getName();
  this->_hitPoints = diamondTrap.getHitPoints();
  this->_energyPoints = diamondTrap.getEnergyPoints();
  this->_attackDamage = diamondTrap.getAttackDamage();
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
  std::cout << "DiamondTrap copy assignment operator is called." << std::endl;
  if (this != &diamondTrap)
  {
    this->_name = diamondTrap.getName();
    this->_hitPoints = diamondTrap.getHitPoints();
    this->_energyPoints = diamondTrap.getEnergyPoints();
    this->_attackDamage = diamondTrap.getAttackDamage();
  }
  return *this;
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap " << this->_name << " destructor is called." << std::endl;
}

void DiamondTrap::whoAmI(void)
{
  std::cout << "My name is " << this->_name << "." << std::endl;
  std::cout << "My ClapTrap name is " << ClapTrap::getName() << "." << std::endl;
}

void DiamondTrap::printStatus(void)
{
  std::cout << "Name: " << this->_name << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
  std::cout << "Hit points: " << this->_hitPoints << std::endl;
  std::cout << "Energy points: " << this->_energyPoints << std::endl;
  std::cout << "Attack damage: " << this->_attackDamage << std::endl;
}
