#include "Zombie.hpp"
#include <iostream>

int main(void)
{
  Zombie zombie = Zombie("Foo");
  zombie.announce();

  Zombie *newZ = newZombie("newZombie");
  newZ->announce();

  randomChump("randomChump");

  delete newZ;
  return (0);
}