#ifndef DOG_H_
#define DOG_H_

#include "Animal.hpp"

class Dog : public Animal
{
public:
  Dog();
  Dog(const Dog &dog);
  Dog &operator=(const Dog &dog);
  virtual ~Dog();

  void makeSound() const;
};

#endif
