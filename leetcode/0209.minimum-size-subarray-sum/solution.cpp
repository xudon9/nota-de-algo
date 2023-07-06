#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/minimum-size-subarray-sum/

struct Solution {
  static int minSubArrayLen(int target, const vector<int> &nums) {
    int sum{}, ir{}, len = nums.size();
    do {
      if (ir == len)
        return 0;
      sum += nums[ir++];
    } while (sum < target);

    int ret{ir}, il{};

    while (1) {
      // DEBUG(0, il, ir, il - ir);
      while (sum - nums[il] >= target) {
        sum -= nums[il++];
      }
      // DEBUG(1, il, ir, il - ir);
      ret = std::min(ret, ir - il);

      if (ir == len)
        break;
      sum += nums[ir++];
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TEST(2, s.minSubArrayLen(7, {2, 3, 1, 2, 4, 3}));
  TEST(1, s.minSubArrayLen(4, {1, 4, 4}));
  TEST(0, s.minSubArrayLen(11, {1, 1, 1, 1, 1, 1, 1, 1}));
  return 0;
}
