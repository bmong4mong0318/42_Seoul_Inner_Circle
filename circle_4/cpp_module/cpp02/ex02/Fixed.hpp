#ifndef FIXED_H_
#define FIXED_H_

#include <cmath>
#include <iostream>

class Fixed
{
private:
  int fixedPoint;
  static const int fractionalBits = 8;

public:
  Fixed();
  explicit Fixed(const int value);
  explicit Fixed(const float value);
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

  /*
  * The 6 comparison operations (>, <, >=, <=, ==, !=)
  ? getRawBits 함수를 통해 반환받은 값을 비교하므로 bool 형태로 반환한다. (true or false)
  */
  bool operator>(const Fixed &fixed);
  bool operator<(const Fixed &fixed);
  bool operator>=(const Fixed &fixed);
  bool operator<=(const Fixed &fixed);
  bool operator==(const Fixed &fixed);
  bool operator!=(const Fixed &fixed);

  /*
  * The 4 arithmetic operators (+, -, *, /)
  ? 산술 연산자는 기존의 float 값에 인자로 받은 값을 이용해 연산 후 반환한다.
  */
  Fixed operator+(const Fixed &fixed);
  Fixed operator-(const Fixed &fixed);
  Fixed operator*(const Fixed &fixed);
  Fixed operator/(const Fixed &fixed);

  /*
  * The 4 increment / decrement operators (++a, a++, --a, a--)
  ? 전위 연산자와 후위 연산자를 구분하기 위해 인자를 void와 int형으로 작성해준다. (C++ 규칙)
  ? 전위 연산자는 레퍼런스로 반환해서 복사하지 않고 원본 값에 접근해서 사용할 수 있다.
  ? 후위 연산자는 임시 객체를 생성해서 반환하고 원본 객체를 연산에 사용하지 않는다.
  ! 함수 내부에서 생성한 임시 객체의 증감을 막기 위해 후위 연산자에서는 함수에 const를 붙여준다.
  */
  Fixed &operator++(void);
  Fixed &operator--(void);
  const Fixed operator++(int);
  const Fixed operator--(int);

  static Fixed &min(Fixed &fixed1, Fixed &fixed2);
  static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
  static Fixed &max(Fixed &fixed1, Fixed &fixed2);
  static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &ofs, const Fixed &fixed);

#endif