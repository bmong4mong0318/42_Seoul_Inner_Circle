#include <string>
#include <iostream>
#include "ReadFile.hpp"

int main(int ac, char **av)
{
  ReadFile readFile;
  try
  {
    if (ac != 4)
      throw "Error: Invalid number of arguments";
    readFile.openFile(av[1], av[2], av[3]);
    return (0);
  }
  catch (const char *error_message)
  {
    std::cout << error_message << std::endl;
    return (1);
  }
}