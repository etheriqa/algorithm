#pragma once

#include <functional>
#include <limits>

template <typename RealType, typename Compare = std::less<RealType>>
RealType
binarySearch(RealType low,
             RealType high,
             RealType value,
             std::function<RealType(RealType)> f,
             size_t n = 100) noexcept {
  RealType mid;
  for (size_t i = 0; i < n; i++) {
    mid = (low + high) / 2;
    if (Compare()(f(mid), value)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return mid;
}
