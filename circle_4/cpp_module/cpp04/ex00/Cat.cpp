#include "Cat.hpp"

Cat::Cat() : Animal()
{
  this->_type = "Cat";
  std::cout << std::setw(15) << "[Cat] "
            << "create!!" << std::endl;
}

Cat::Cat(const Cat &cat)
{
  this->_type = cat.getType();
  std::cout << std::setw(15) << "[Cat] "
            << "copy!!" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
  if (this != &cat)
    this->_type = cat.getType();
  return *this;
}

Cat::~Cat()
{
  std::cout << std::setw(15) << "[Cat] "
            << "delete!!" << std::endl;
}

void Cat::makeSound() const
{
  std::cout << "Meow! Meow!" << std::endl;
}
