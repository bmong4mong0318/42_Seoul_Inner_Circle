#include "AMateria.hpp"

AMateria::AMateria()
  : _type("") {
  std::cout << std::setw(15) << "[AMateria] " << "create!!" << std::endl;
}

AMateria::AMateria(std::string const& type)
  : _type(type) {
  std::cout << std::setw(15) << "[AMateria] " << "create!!" << std::endl;
}

AMateria::AMateria(const AMateria& ref)
  : _type(ref.getType()) {
  std::cout << std::setw(15) << "[AMateria] " << "copy!!" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& ref) {
  std::cout << std::setw(15) << "[AMateria] " << "operator=!!" << std::endl;
  if (this != &ref) {
    /* insert */
    this->_type = ref.getType();
  }
  return *this;
}

AMateria::~AMateria() {
  std::cout << std::setw(15) << "[AMateria] " << "delete!!" << std::endl;
}

std::string const& AMateria::getType() const {
  return this->_type;
}

void AMateria::use(ICharacter& target) {
  std::cout << "This message will not print. " << target.getName() << " is not used too." << std::endl;
}
