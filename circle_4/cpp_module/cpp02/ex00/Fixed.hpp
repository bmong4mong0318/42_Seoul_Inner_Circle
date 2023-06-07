#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>

class Fixed
{
private:
  int number;
  static const int bits = 8;

public:
  Fixed();
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
