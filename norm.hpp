#ifndef MYLIB_INTEGER_NORM_HPP_
#define MYLIB_INTEGER_NORM_HPP_
#include <type_traits>  //enable_if_t


namespace mylib {

// Tが組み込みの整数型の場合。
template <typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
constexpr auto norm_impl(const T& x) -> T {
  return (x >= 0) ? x : -x;
};

// Tが組み込みの整数型でない場合。その型でメンバ関数norm()を実装する必要がある。
template <typename T, std::enable_if_t<!std::is_integral<T>::value, std::nullptr_t> = nullptr>
constexpr auto norm_impl(const T& x) -> typename T::value_type {
  return x.norm();
};

template <typename T>
constexpr decltype(auto) norm(const T& x) {
  return norm_impl(x);
}

};  //namespace mylib


#endif  //MYLIB_INTEGER_NORM_HPP_
