#include "gtest/gtest.h"

#include "math/golden_section_search.h"

namespace {
const double kPI = 3.1415926535898;
}

TEST(Math, GoldenSectionSearchSin) {
  const auto f = [](double x){ return std::sin(x); };
  double x, sin_x;
  std::tie(x, sin_x) =
    goldenSectionSearch<double>(0, kPI, f);
  EXPECT_NEAR(kPI / 2, x, 1e-6);
  EXPECT_NEAR(1, sin_x, 1e-6);
}

TEST(Math, GoldenSectionSearchCos) {
  const auto f = [](double x){ return std::cos(x); };
  double x, cos_x;
  std::tie(x, cos_x) =
    goldenSectionSearch<double, std::greater<double>>(0, 2 * kPI, f);
  EXPECT_NEAR(kPI, x, 1e-6);
  EXPECT_NEAR(-1, cos_x, 1e-6);
}
