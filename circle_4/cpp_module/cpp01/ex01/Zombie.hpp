#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <string>

class Zombie
{
private:
  std::string _name;

public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie();
  void announce(void);
  void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif