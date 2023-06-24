#ifndef MateriaSource_HPP
#define MateriaSource_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
  AMateria *_amateria[4];

public:
  MateriaSource();
  MateriaSource(const MateriaSource &ref);
  MateriaSource &operator=(const MateriaSource &ref);
  ~MateriaSource();

  const AMateria *getAMateria(int idx) const;
  void learnMateria(AMateria *amateria);
  AMateria *createMateria(const std::string &type);
};

#endif // MateriaSource_HPP
