#pragma once

#include <tuple>
#include <type_traits>

template <typename Arithmetic>
std::tuple<Arithmetic, Arithmetic>
extendedEuclidean(Arithmetic a, Arithmetic b) {
  static_assert(std::is_unsigned<Arithmetic>::value == false,
                "Arithmetic type must be unsigned.");
  Arithmetic x, y;
  if (b == 0) {
    return {1, 0};
  } else if (a < b) {
    std::tie(y, x) = extendedEuclidean(b, a);
    return {x, y};
  } else {
    std::tie(x, y) = extendedEuclidean(b, a % b);
    return {y, x - a / b * y};
  }
}
