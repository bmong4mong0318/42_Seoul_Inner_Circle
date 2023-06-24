#ifndef WrongCat_HPP
#define WrongCat_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
  WrongCat();
  WrongCat(const WrongCat &ref);
  WrongCat &operator=(const WrongCat &ref);

  virtual ~WrongCat();
  void makeSound() const;
};

#endif // WrongCat_HPP
