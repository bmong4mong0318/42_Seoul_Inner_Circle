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
  /*
  ? float 생성자는 float형이 비트연산이 불가능하기 때문에 num * (1 << bits) 형식으로 저장한다.
  ? 또한, 42.42 * 256을 저장할 때, 10859.52를 소숫점 아래 값이 사라지므로 조금 더 근사치를 저장하기 위해 roundf 함수를 사용해준다.
  */
  explicit Fixed(const float value);
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
};

/*
? output stream 객체에 대한 연산자 오버로딩이기 때문에 클래스 밖에 선언해준다.
? ostream 객체인 ofs에 부동 소수점 값을 입력해준다.
*/
std::ostream &operator<<(std::ostream &ofs, const Fixed &fixed);

#endif