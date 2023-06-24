#include "Dog.hpp"

Dog::Dog() : Animal()
{
  this->_type = "Dog";
  std::cout << std::setw(15) << "[Dog] "
            << "create!!" << std::endl;
}

Dog::Dog(const Dog &dog)
{
  this->_type = dog.getType();
  std::cout << std::setw(15) << "[Dog] "
            << "copy!!" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
  if (this != &dog)
    this->_type = dog.getType();
  return *this;
}

Dog::~Dog()
{
  std::cout << std::setw(15) << "[Dog] "
            << "delete!!" << std::endl;
}

void Dog::makeSound() const
{
  std::cout << "Woof! Woof!" << std::endl;
}
