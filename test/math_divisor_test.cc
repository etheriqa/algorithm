#include "gtest/gtest.h"

#include "math/divisor.h"

TEST(Math, Divisor) {
  using Container = std::vector<int>;
  EXPECT_EQ(Container({1}), divisor(1));
  EXPECT_EQ(Container({1, 2}), divisor(2));
  EXPECT_EQ(Container({1, 3}), divisor(3));
  EXPECT_EQ(Container({1, 2, 4}), divisor(4));
  EXPECT_EQ(Container({1, 5}), divisor(5));
  EXPECT_EQ(Container({1, 2, 3, 6}), divisor(6));
  EXPECT_EQ(Container({1, 7}), divisor(7));
  EXPECT_EQ(Container({1, 2, 4, 8}), divisor(8));
  EXPECT_EQ(Container({1, 3, 9}), divisor(9));
  EXPECT_EQ(Container({1, 2, 5, 10}), divisor(10));
  EXPECT_EQ(Container({1, 11}), divisor(11));
  EXPECT_EQ(Container({1, 2, 3, 4, 6, 12}), divisor(12));
}
