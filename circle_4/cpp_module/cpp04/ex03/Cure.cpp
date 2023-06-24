#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << std::setw(15) << "[Cure] " << "create!!" << std::endl;
}

Cure::Cure(const Cure& ref) : AMateria(ref.getType()) {
  std::cout << std::setw(15) << "[Cure] " << "copy!!" << std::endl;
}

Cure&	Cure::operator=(const Cure& ref) {
  std::cout << std::setw(15) << "[Cure] " << "operator=!!" << std::endl;
  if (this != &ref) {
    this->_type = ref.getType();
  }
  return *this;
}

Cure::~Cure() {
  std::cout << std::setw(15) << "[Cure] " << "delete!!" << std::endl;
}

AMateria* Cure::clone() const {
  return (new Cure());
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}