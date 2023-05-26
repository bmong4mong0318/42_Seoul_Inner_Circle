#include "Zombie.hpp"
#include <sstream>

Zombie *zombieHorde(int N, std::string name)
{
  if (N < 0)
    throw "Error: Invalid number of zombies";
  Zombie *zHorde = new Zombie[N];
  std::stringstream stringStream;

  for (int i = 0; i < N; i++)
  {
    stringStream.str(std::string());
    stringStream << i + 1;
    zHorde[i].setName(name + "_" + stringStream.str());
  }
  return zHorde;
}
