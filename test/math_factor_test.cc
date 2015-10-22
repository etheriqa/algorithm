#include "gtest/gtest.h"

#include "math/factor.h"

TEST(Math, Factor) {
  using Container = std::map<int, int>;
  EXPECT_TRUE(factor(1).empty());
  EXPECT_EQ(Container({{2, 1}}), factor(2));
  EXPECT_EQ(Container({{3, 1}}), factor(3));
  EXPECT_EQ(Container({{2, 2}}), factor(4));
  EXPECT_EQ(Container({{5, 1}}), factor(5));
  EXPECT_EQ(Container({{2, 1}, {3, 1}}), factor(6));
  EXPECT_EQ(Container({{7, 1}}), factor(7));
  EXPECT_EQ(Container({{2, 3}}), factor(8));
  EXPECT_EQ(Container({{3, 2}}), factor(9));
  EXPECT_EQ(Container({{2, 1}, {5, 1}}), factor(10));
  EXPECT_EQ(Container({{11, 1}}), factor(11));
  EXPECT_EQ(Container({{2, 2}, {3, 1}}), factor(12));
}
