#include <iostream>
#include "gcd.hpp"


int main()
{
  int a = 390;
  int b = -273;

  std::cout << mylib::gcd(a, b) << std::endl;

  return 0;
}
