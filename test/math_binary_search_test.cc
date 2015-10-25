#include "gtest/gtest.h"

#include "math/binary_search.h"

TEST(Math, BinarySearch) {
  const auto f = [](double x){ return x * x; };

  EXPECT_NEAR(5, binarySearch<double>(0, 100, 25, f), 1e-6);
  EXPECT_NEAR(5, binarySearch<double>(0, 5, 25, f), 1e-6);
  EXPECT_NEAR(5, binarySearch<double>(5, 100, 25, f), 1e-6);
}
