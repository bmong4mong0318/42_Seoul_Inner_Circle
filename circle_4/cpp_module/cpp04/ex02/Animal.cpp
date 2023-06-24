#include "Animal.hpp"

Animal::Animal()
    : _type("Animal")
{
  std::cout << std::setw(15) << "[Animal] "
            << "create!!" << std::endl;
}

Animal::Animal(const Animal &animal)
    : _type(animal.getType())
{
  std::cout << std::setw(15) << "[Animal] "
            << "copy!!" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
  if (this != &animal)
  {
    this->_type = animal._type;
  }
  return (*this);
}

Animal::~Animal()
{
  std::cout << std::setw(15) << "[Animal] "
            << "delete!!" << std::endl;
}

std::string Animal::getType() const
{
  return this->_type;
}

std::ostream &operator<<(std::ostream &ofs, const Animal &animal)
{
  return ofs << animal.getType();
}
