#include "../../common.hpp"

// https://leetcode.com/problems/stone-game-iv/

class Solution {
  std::map<int, bool> cache;

  bool go(int n) {
    if (n == 0)
      return false;
    auto [it, ite] = cache.equal_range(n);
    if (it != ite)
      return it->second;

    bool w = false;
    for (int i = 1; i * i <= n; ++i) {
      int rest = n - i * i;
      if (!go(rest)) {
        w = true;
        break;
      }
    }
    cache.emplace_hint(it, n, w);
    return w;
  }

public:
  bool winnerSquareGame(int n) {
    cache.clear();
    return go(n);
  }
};
