#pragma once

#include <cmath>
#include <vector>

template <typename Integral, typename Container = std::vector<Integral>>
Container
divisor(Integral n) {
  Container divisors({1, n});
  for (Integral i = 2; i <= std::sqrt(n); i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      divisors.push_back(n / i);
    }
  }
  std::sort(divisors.begin(), divisors.end());
  divisors.erase(std::unique(divisors.begin(), divisors.end()), divisors.end());
  return divisors;
}
