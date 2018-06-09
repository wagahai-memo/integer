#ifndef MYLIB_INTEGER_DEVIDE_HPP_
#define MYLIB_INTEGER_DEVIDE_HPP_


namespace mylib {

template <typename T>
constexpr auto abs(T x) {
  return (x >= 0) ? x : -x;
}

//------------------------------
//
//  余りがdivide_modで定義された条件を満たすときの商を返す。
//
//------------------------------
template <typename T>
constexpr T devide(T x, T y) {
  if (abs(x) % abs(y) == 0)
    return x / y;
  if (x < 0 && y > 0)
    return x / y - 1;
  else if (x < 0 && y < 0)
    return x / y + 1;
  return x / y;
}


//------------------------------
//
//  組み込みの整数型で、商と余りを求める関数。
//  余りは、0以上で除数より小さくなる整数で返す。
//
//------------------------------
template <typename T>
constexpr T devide_mod(T x, T y) {
  return x - y * devide(x, y);
}

}
#endif  //MYLIB_INTEGER_DEVIDE_HPP_
