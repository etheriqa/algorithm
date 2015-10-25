#include "gtest/gtest.h"

#include "math/extended_euclidean.h"

TEST(Math, ExtendedEuclidean) {
  EXPECT_EQ(std::make_tuple(0, 1), extendedEuclidean(0, 1));
  EXPECT_EQ(std::make_tuple(0, 1), extendedEuclidean(1, 1));
  EXPECT_EQ(std::make_tuple(1, 0), extendedEuclidean(1, 2));
  EXPECT_EQ(std::make_tuple(-1, 1), extendedEuclidean(2, 3));
  EXPECT_EQ(std::make_tuple(1, -2), extendedEuclidean(60, 24));
  EXPECT_EQ(std::make_tuple(-12, 1), extendedEuclidean(30, 365));
}
