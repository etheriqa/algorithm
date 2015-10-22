#pragma once

#include <cstddef>

class Dice {
private:
  size_t top_, front_, right_;
public:
  Dice() noexcept : Dice(1, 2, 3) {}
  Dice(size_t top, size_t front, size_t right) noexcept :
    top_(top), front_(front), right_(right) {}
  size_t top() const noexcept { return top_; }
  size_t bottom() const noexcept { return 7 - top_; }
  size_t front() const noexcept { return front_; }
  size_t back() const noexcept { return 7 - front_; }
  size_t right() const noexcept { return right_; }
  size_t left() const noexcept { return 7 - right_; }
  Dice rollFront() const noexcept { return Dice(back(), top(), right()); }
  Dice rollBack() const noexcept { return Dice(front(), bottom(), right()); }
  Dice rollRight() const noexcept { return Dice(left(), front(), top()); }
  Dice rollLeft() const noexcept { return Dice(right(), front(), bottom()); }
};
