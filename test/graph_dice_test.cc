#include "graph/dice.h"
#include "gtest/gtest.h"

TEST(Graph, Dice) {
  const Dice dice;
  EXPECT_EQ(1, dice.top());
  EXPECT_EQ(6, dice.bottom());
  EXPECT_EQ(2, dice.front());
  EXPECT_EQ(5, dice.back());
  EXPECT_EQ(3, dice.right());
  EXPECT_EQ(4, dice.left());
}

TEST(Graph, DiceRollFront) {
  const auto dice = Dice().rollFront();
  EXPECT_EQ(5, dice.top());
  EXPECT_EQ(2, dice.bottom());
  EXPECT_EQ(1, dice.front());
  EXPECT_EQ(6, dice.back());
  EXPECT_EQ(3, dice.right());
  EXPECT_EQ(4, dice.left());
}

TEST(Graph, DiceRollBack) {
  const auto dice = Dice().rollBack();
  EXPECT_EQ(2, dice.top());
  EXPECT_EQ(5, dice.bottom());
  EXPECT_EQ(6, dice.front());
  EXPECT_EQ(1, dice.back());
  EXPECT_EQ(3, dice.right());
  EXPECT_EQ(4, dice.left());
}

TEST(Graph, DiceRollRight) {
  const auto dice = Dice().rollRight();
  EXPECT_EQ(4, dice.top());
  EXPECT_EQ(3, dice.bottom());
  EXPECT_EQ(2, dice.front());
  EXPECT_EQ(5, dice.back());
  EXPECT_EQ(1, dice.right());
  EXPECT_EQ(6, dice.left());
}

TEST(Graph, DiceRollLeft) {
  const auto dice = Dice().rollLeft();
  EXPECT_EQ(3, dice.top());
  EXPECT_EQ(4, dice.bottom());
  EXPECT_EQ(2, dice.front());
  EXPECT_EQ(5, dice.back());
  EXPECT_EQ(6, dice.right());
  EXPECT_EQ(1, dice.left());
}
