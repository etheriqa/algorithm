#pragma once

#include <vector>

template <typename Arithmetic>
class BIT {
private:
  std::vector<Arithmetic> values_;
public:
  explicit BIT(size_t n) : values_(n) {}
  void add(size_t pos, const Arithmetic& value) {
    for (size_t p = pos + 1; p <= values_.size(); p += p & -p) {
      values_[p] += value;
    }
  }
  Arithmetic sum(size_t n) const {
    Arithmetic sum = 0;
    for (size_t p = n; p > 0; p -= p & -p) {
      sum += values_[p];
    }
    return sum;
  }
};
