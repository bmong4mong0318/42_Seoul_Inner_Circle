#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <string>
#include <iomanip>

class Animal
{
protected:
  std::string _type;

public:
  Animal();
  Animal(const Animal &animal);
  Animal &operator=(const Animal &animal);
  virtual ~Animal();

  virtual void makeSound() const;
  std::string getType() const;
};

std::ostream &operator<<(std::ostream &ofs, const Animal &animal);

#endif
