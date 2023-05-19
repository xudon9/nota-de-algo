#include "../../common.hpp"

/*
 * https://leetcode.com/problems/maximize-score-after-n-operations
 */
#include <cstdint>
#include <numeric>

struct Solution {
  std::map<uint16_t, int> cache;
  vector<int> *nums;

  int maxScoreWithMask(uint16_t mask) {
    int size = nums->size();
    int to_set = size - __builtin_popcount(mask);

    if (!to_set)
      return 0;
    auto it = cache.emplace(mask, 0).first;
    if (it->second > 0)
      return it->second;

    int max_score = -1;
    for (int i = 0; i < size; ++i) {
      if (mask & (1u << i))
        continue;
      for (int j = i + 1; j < size; ++j) {
        if (mask & (1u << j))
          continue;
        uint16_t new_mask = mask | (1u << i) | (1u << j);
        auto &n = *nums;
        int score =
            to_set / 2 * std::gcd(n[i], n[j]) + maxScoreWithMask(new_mask);
        max_score = std::max(max_score, score);
      }
    }
    return it->second = max_score;
  }

  int maxScore(vector<int> &nums) {
    this->nums = &nums;
    cache.clear();
    return maxScoreWithMask(0);
  }
};

int main() {
  vector<int> nums = {1,2,3,4,5,6};
  Solution s;
  auto i = s.maxScore(nums);
  DEBUG(i);
}
