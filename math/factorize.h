#pragma once

#include <cmath>
#include <map>

template <typename Integral, typename Container = std::map<Integral, Integral>>
Container
factorize(Integral n) {
  Container factor;
  for (Integral i = 2; i <= std::sqrt(n); i++) {
    while (n % i == 0) {
      n /= i;
      factor[i]++;
    }
  }
  if (n > 1) {
    factor[n]++;
  }
  return factor;
}
