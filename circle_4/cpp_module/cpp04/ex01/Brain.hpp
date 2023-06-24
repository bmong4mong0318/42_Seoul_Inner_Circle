#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Brain
{
private:
  std::string ideas[100];

public:
  Brain();
  Brain(const Brain &ref);
  Brain &operator=(const Brain &ref);
  ~Brain();

  std::string getIdeas(int n) const;
  void setIdeas(std::string idea, int n);
};

#endif // Brain_HPP
