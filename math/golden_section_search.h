#pragma once

#include <cmath>
#include <functional>
#include <tuple>

template <typename RealType, typename Compare = std::less<RealType>>
std::tuple<RealType, RealType>
goldenSectionSearch(RealType low,
                    RealType high,
                    std::function<RealType(RealType)> f,
                    size_t n = 100) noexcept {
  const RealType phi = (1 + std::sqrt(5)) / 2;
  RealType mid0 = (low * phi + high) / (1 + phi);
  RealType mid1 = (low + phi * high) / (1 + phi);
  RealType f0 = f(mid0);
  RealType f1 = f(mid1);
  for (size_t i = 0; i < n; i++) {
    if (Compare()(f0, f1)) {
      low = mid0;
      mid0 = mid1;
      mid1 = (low + phi * high) / (1 + phi);
      f0 = f1;
      f1 = f(mid1);
    } else {
      high = mid1;
      mid1 = mid0;
      mid0 = (low * phi + high) / (1 + phi);
      f1 = f0;
      f0 = f(mid0);
    }
  }
  return std::make_tuple(mid0, f0);
}
