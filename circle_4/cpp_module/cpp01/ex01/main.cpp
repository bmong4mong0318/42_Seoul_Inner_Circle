#include "Zombie.hpp"
#include <iostream>
#include <stdlib.h>

int main(void)
{
  Zombie zombie = Zombie("da");
  zombie.announce();

  int N = 5;
  try
  {
    Zombie *zHorde = zombieHorde(N, "yun");
    for (int i = 0; i < N; i++)
    {
      zHorde[i].announce();
    }
    delete[] zHorde;
    return (0);
  }
  catch (const char *error_message)
  {
    std::cout << error_message << std::endl;
    return (1);
  }
}