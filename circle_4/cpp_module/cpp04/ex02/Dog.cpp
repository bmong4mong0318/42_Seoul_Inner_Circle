#include "Dog.hpp"

Dog::Dog() : Animal()
{
  std::cout << std::setw(15) << "[Dog] "
            << "create!!" << std::endl;
  this->_type = "Dog";
  this->brain = new Brain();
}

Dog::Dog(const Dog &dog)
{
  this->_type = dog.getType();
  this->brain = new Brain(*dog.getBrain());
  std::cout << std::setw(15) << "[Dog] "
            << "copy!!" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
  std::cout << std::setw(15) << "[Dog] "
            << "operator=!!" << std::endl;
  if (this != &dog)
  {
    this->_type = dog.getType();
    this->brain = new Brain(*dog.getBrain());
  }
  return *this;
}

Dog::~Dog()
{
  delete this->brain;
  std::cout << std::setw(15) << "[Dog] "
            << "delete!!" << std::endl;
}

void Dog::makeSound() const
{
  std::cout << "Woof! Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
  return this->brain;
}
