#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
  void (Harl::*f[4])(void) = {
      &Harl::debug,
      &Harl::info,
      &Harl::warning,
      &Harl::error};
  std::string findComplain("DEBUG,INFO,WARNING,ERROR");

  size_t pos = level.find(",");
  if (pos >= 0 && pos <= findComplain.length())
  {
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return;
  }

  switch (findComplain.find(level))
  {
  case 11:
    std::cout << "[ WARNING ]" << std::endl;
    (this->*f[2])();
    std::cout << std::endl;
  case 19:
    std::cout << "[ ERROR ]" << std::endl;
    (this->*f[3])();
    std::cout << std::endl;
    break;
  case 0:
    std::cout << "[ DEBUG ]" << std::endl;
    (this->*f[0])();
    std::cout << std::endl;
  case 6:
    std::cout << "[ INFO ]" << std::endl;
    (this->*f[1])();
    std::cout << std::endl;

  default:
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  }
}

void Harl::debug()
{
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
  std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
  std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
