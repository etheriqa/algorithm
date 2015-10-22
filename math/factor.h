#pragma once

#include <cmath>
#include <map>

template <typename Integral, typename Container = std::map<Integral, Integral>>
Container
factor(Integral n) {
  Container factors;
  for (Integral i = 2; i <= std::sqrt(n); i++) {
    while (n % i == 0) {
      n /= i;
      factors[i]++;
    }
  }
  if (n > 1) {
    factors[n]++;
  }
  return factors;
}
