#ifndef Cure_HPP
#define Cure_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AMateria.hpp"

class Cure : public AMateria {
  public:
    Cure();
    Cure(const Cure& ref);
    Cure&	operator=(const Cure& ref);
    ~Cure();
    
    AMateria *clone() const;
    void use(ICharacter& target);

};

#endif  //Cure_HPP
