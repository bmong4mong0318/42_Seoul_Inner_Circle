#ifndef CAT_H_
#define CAT_H_

#include "Animal.hpp"

class Cat : public Animal
{
public:
  Cat();
  Cat(const Cat &cat);
  Cat &operator=(const Cat &cat);
  virtual ~Cat();

  void makeSound() const;
};

#endif
