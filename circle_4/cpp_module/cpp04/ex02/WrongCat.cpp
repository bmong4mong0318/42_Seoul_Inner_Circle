#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal()
{
  this->_type = "WrongAnimal";
  std::cout << std::setw(15) << "[WrongCat] "
            << "create!!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref)
{
  this->_type = ref.getType();
  std::cout << std::setw(15) << "[WrongCat] "
            << "copy!!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &ref)
{
  std::cout << std::setw(15) << "[WrongCat] "
            << "operator=!!" << std::endl;
  if (this != &ref)
  {
    this->_type = ref.getType();
  }
  return *this;
}

WrongCat::~WrongCat()
{
  std::cout << std::setw(15) << "[WrongCat] "
            << "delete!!" << std::endl;
}

void WrongCat::makeSound() const
{
  std::cout << "WrongCat sound ~~~" << std::endl;
}