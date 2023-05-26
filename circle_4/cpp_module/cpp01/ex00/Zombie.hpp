#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <string>
#include <iostream>

class Zombie
{
private:
  std::string _name;

public:
  Zombie(std::string name);
  ~Zombie();
  void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif