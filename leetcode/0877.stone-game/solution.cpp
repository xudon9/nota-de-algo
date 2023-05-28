#include "../../common.hpp"

/* https://leetcode.com/problems/stone-game/
 *
 * This is not the best solution.
 * Alice always win :)
 */
#include <cstdint>

class Solution {
  using Range = std::pair<uint16_t, uint16_t>;
  using Result = std::pair<uint32_t, uint32_t>;

  std::map<Range, Result> cache;
  vector<int> piles;

  Result go(Range r) {
    if (r.first == r.second)
      return std::make_pair(0u, 0u);
    assert(r.first < r.second);
    auto [it, it2] = cache.equal_range(r);
    if (it != it2)
      return it->second;

    Result r1, r2;

    {
      Range key = r;
      ++key.first;
      Result save = go(key);
      r1 = std::make_pair(save.second + piles[r.first], save.first);
    };

    {
      Range key = r;
      --key.second;
      Result save = go(key);
      r2 = std::make_pair(save.second + piles[r.second-1], save.first);
    };

    r1 = std::max(r1, r2);
    cache.emplace_hint(it, r, r1);
    return r1;
  }

public:
  bool stoneGame(vector<int> &p) {
    piles = std::move(p);
    cache.clear();
    auto [alice, bob] = go(std::make_pair(0, piles.size()));
    return alice > bob;
  }
};
