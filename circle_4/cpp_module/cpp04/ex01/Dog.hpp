#ifndef DOG_H_
#define DOG_H_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
  Brain *brain;

public:
  Dog();
  Dog(const Dog &dog);
  Dog &operator=(const Dog &dog);
  virtual ~Dog();

  void makeSound() const;
  Brain *getBrain() const;
};

#endif
