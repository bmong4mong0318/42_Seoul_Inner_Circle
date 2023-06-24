#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
  std::cout << std::setw(15) << "[Ice] "
            << "create!!" << std::endl;
}

Ice::Ice(const Ice &ref) : AMateria(ref.getType())
{
  std::cout << std::setw(15) << "[Ice] "
            << "copy!!" << std::endl;
}

Ice &Ice::operator=(const Ice &ref)
{
  std::cout << std::setw(15) << "[Ice] "
            << "operator=!!" << std::endl;
  if (this != &ref)
  {
    this->_type = ref.getType();
  }
  return *this;
}

Ice::~Ice()
{
  std::cout << std::setw(15) << "[Ice] "
            << "delete!!" << std::endl;
}

AMateria *Ice::clone() const
{
  return (new Ice());
}

void Ice::use(ICharacter &target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}