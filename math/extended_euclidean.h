#pragma once

#include <tuple>

template <typename Integral>
std::tuple<Integral, Integral>
extendedEuclidean(Integral a, Integral b) {
  Integral x, y;
  if (b == 0) {
    return std::make_tuple(1, 0);
  } else if (a < b) {
    std::tie(y, x) = extendedEuclidean(b, a);
    return std::make_tuple(x, y);
  } else {
    std::tie(x, y) = extendedEuclidean(b, a % b);
    return std::make_tuple(y, x - a / b * y);
  }
}
