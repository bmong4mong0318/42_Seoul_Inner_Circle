#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <string>
#include <iomanip>

class Animal
{
protected:
  std::string _type;

public:
  Animal();
  Animal(const Animal &animal);
  Animal &operator=(const Animal &animal);
  virtual ~Animal(); // 가상 소멸자의 선언

  // 순수 가상 함수(pure virtual function)란 파생 클래스에서 반드시 재정의해야 하는 멤버 함수
  // 위와 같이 함수만 있고 본체가 없다는 의미로 함수 선언부 끝에 "=0"을 추가합니다.
  virtual void makeSound() const = 0; // 순수가상 함수의 선언
  std::string getType() const;
};

std::ostream &operator<<(std::ostream &ofs, const Animal &animal);

#endif
