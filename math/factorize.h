#pragma once

#include <cmath>
#include <map>

std::map<std::uint_least64_t, std::uint_least8_t>
factorize(std::uint_least64_t n) {
  std::map<std::uint_least64_t, std::uint_least8_t> factor;
  for (std::uint_least64_t i = 2; n > 1 && i <= std::floor(std::sqrt(n)); i++) {
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
