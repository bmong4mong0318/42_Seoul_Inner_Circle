#include "Fixed.hpp"

Fixed::Fixed(void)
    : fixedPoint(0)
{
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
    : fixedPoint(value << Fixed::fractionalBits)
{
  // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : fixedPoint(static_cast<int>(roundf(value * (1 << Fixed::fractionalBits))))
{
  // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
  // std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
  // std::cout << "Copy assignation operator called" << std::endl;
  if (this != &fixed)
    this->fixedPoint = fixed.getRawBits();
  return *this;
}

Fixed::~Fixed(void)
{
  // std::cout << "Destructor called" << std::endl;
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

/*
* A member function int toInt( void ) const;
  ! that converts the fixed-point value to an integer value.
*/
int Fixed::toInt(void) const
{
  return this->fixedPoint >> Fixed::fractionalBits;
}

/*
 * The 6 comparison operations (>, <, >=, <=, ==, !=)
 */
bool Fixed::operator>(const Fixed &fixed)
{
  return this->fixedPoint > fixed.fixedPoint;
}

bool Fixed::operator<(const Fixed &fixed)
{
  return this->fixedPoint < fixed.fixedPoint;
}

bool Fixed::operator>=(const Fixed &fixed)
{
  return this->fixedPoint >= fixed.fixedPoint;
}

bool Fixed::operator<=(const Fixed &fixed)
{
  return this->fixedPoint <= fixed.fixedPoint;
}

bool Fixed::operator==(const Fixed &fixed)
{
  return this->fixedPoint == fixed.fixedPoint;
}

bool Fixed::operator!=(const Fixed &fixed)
{
  return this->fixedPoint != fixed.fixedPoint;
}

/*
 * The 4 arithmetic operators (+, -, *, /)
 */
Fixed Fixed::operator+(const Fixed &fixed)
{
  return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed)
{
  return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed)
{
  return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed)
{
  return Fixed(this->toFloat() / fixed.toFloat());
}

/*
 * The 4 increment / decrement operators (++a, a++, --a, a--)
 */
Fixed &Fixed::operator++(void)
{
  this->fixedPoint++;
  return *this;
}

Fixed &Fixed::operator--(void)
{
  this->fixedPoint--;
  return *this;
}

const Fixed Fixed::operator++(int)
{
  const Fixed tmp(*this);

  this->fixedPoint++;
  return tmp;
}

const Fixed Fixed::operator--(int)
{
  const Fixed tmp(*this);

  this->fixedPoint--;
  return tmp;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
  return (fixed1.getRawBits() <= fixed2.getRawBits()) ? fixed1 : fixed2;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
  return (fixed1.getRawBits() <= fixed2.getRawBits()) ? fixed1 : fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
  return (fixed1.getRawBits() <= fixed2.getRawBits()) ? fixed2 : fixed1;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
  return (fixed1.getRawBits() <= fixed2.getRawBits()) ? fixed2 : fixed1;
}

std::ostream &operator<<(std::ostream &ofs, const Fixed &fixed)
{
  return ofs << fixed.toFloat();
}