#include "../../common.hpp"
// URL: https://leetcode.com/problems/sort-the-jumbled-numbers/

struct Solution {
  static vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    vector<std::pair<int, int>> mapped;
    mapped.reserve(nums.size());

    for (size_t i = 0; i < nums.size(); ++i) {
      int weight{1}, v{}, from{nums[i]};
      // Do it at least once! Because of "0" should be regarded as a single-digit number
      do {
        v += mapping[from % 10] * weight;
        from /= 10;
        weight *= 10;
      } while (from);
      mapped.emplace_back(v, i);
    }

    std::sort(mapped.begin(), mapped.end());

    vector<int> result(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
      result[i] = nums[mapped[i].second];
    }

    // DEBUG(mapped, result);

    return result;
  }
};

int main() {
  vector<int> mapping{8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
  vector<int> nums{991, 338, 38};
  Solution::sortJumbled(mapping, nums);
}
