#include "Fixed.hpp"

Fixed::Fixed(void)
    : fixedPoint(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
    : fixedPoint(value << Fixed::fractionalBits)
{
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : fixedPoint(static_cast<int>(roundf(value * (1 << Fixed::fractionalBits))))
{
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
  std::cout << "Copy assignation operator called" << std::endl;
  if (this != &fixed)
    this->fixedPoint = fixed.getRawBits();
  return *this;
}

Fixed::~Fixed(void)
{
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
  return this->fixedPoint;
}

void Fixed::setRawBits(const int raw)
{
  this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
  return static_cast<float>(this->fixedPoint) / (1 << Fixed::fractionalBits);
}

int Fixed::toInt(void) const
{
  return this->fixedPoint >> Fixed::fractionalBits;
}

std::ostream &operator<<(std::ostream &ofs, const Fixed &fixed)
{
  return ofs << fixed.toFloat();
}
