#pragma once

#include <tuple>
#include <unordered_map>

template <typename Key>
class UnionFind {
private:
  std::unordered_map<Key, std::tuple<Key, size_t>> parent_;
public:
  UnionFind() {}
  void insert(const Key& key) noexcept {
    parent_.emplace(key, std::make_tuple(key, 0));
  }
  Key find(const Key& key) noexcept {
    auto& root = tree_.at(key);
    if (key == std::get<0>(root)) {
      return key;
    } else {
      return std::get<0>(root) = find(std::get<0>(root));
    }
  }
  void merge(const Key& a, const Key& b) noexcept {
    auto& root_a = tree_.at(find(a));
    auto& root_b = tree_.at(find(b));
    if (root_a == root_b) {
      return;
    } else if (std::get<1>(root_a) < std::get<1>(root_b)) {
      std::get<0>(root_a) = std::get<0>(root_b);
    } else {
      std::get<0>(root_b) = std::get<0>(root_a);
      if (std::get<1>(root_a) == std::get<1>(root_b)) {
        std::get<1>(root_a)++;
      }
    }
  }
};
