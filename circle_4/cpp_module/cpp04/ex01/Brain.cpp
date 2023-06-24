#include "Brain.hpp"

Brain::Brain()
{
  for (int i = 0; i < 100; i++)
  {
    this->ideas[i] = 'A' + (i % 26);
  }
  std::cout << std::setw(15) << "[Brain] "
            << "create!!" << std::endl;
}

Brain::Brain(const Brain &ref)
{
  for (int i = 0; i < 100; i++)
  {
    this->setIdeas(ref.getIdeas(i), i);
  }
  std::cout << std::setw(15) << "[Brain] "
            << "copy!!" << std::endl;
}

Brain &Brain::operator=(const Brain &ref)
{
  std::cout << std::setw(15) << "[Brain] "
            << "operator=!!" << std::endl;
  if (this != &ref)
  {
    for (int i = 0; i < 100; i++)
    {
      this->setIdeas(ref.getIdeas(i), i);
    }
  }
  return *this;
}

Brain::~Brain()
{
  std::cout << std::setw(15) << "[Brain] "
            << "delete!!" << std::endl;
}

std::string Brain::getIdeas(int n) const
{
  return this->ideas[n];
}

void Brain::setIdeas(std::string idea, int n)
{
  this->ideas[n] = idea;
}