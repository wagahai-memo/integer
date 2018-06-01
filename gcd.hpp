#ifndef MYLIB_INTEGER_GCD_HPP_
#define MYLIB_INTEGER_GCD_HPP_
#include <type_traits>  //enable_if_t
#include "norm.hpp"
#include "devide.hpp"


namespace mylib {

//組み込み型の整数の場合
template <typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
constexpr T gcd_impl(const T& a, const T& b) {
  return (b == 0) ? a : gcd_impl(b, devide_mod(a, b));
}

//組み込み型でない場合、その型で operator%()を実装する必要がある
template <typename T, std::enable_if_t<!std::is_integral<T>::value, std::nullptr_t> = nullptr>
constexpr T gcd_impl(const T& a, const T& b) {
  return (b == static_cast<T>(0)) ? a : gcd_impl(b, a % b);
}

template <typename T>
constexpr T gcd(const T& a, const T& b) {
  return (norm(a) >= norm(b)) ? gcd_impl(a, b) : gcd_impl(b, a);
}

};  //namespace mylib


#endif  //MYLIB_INTEGER_GCD_HPP_
