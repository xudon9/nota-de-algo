#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
  static int longestSubarray(const vector<int> &nums) {
    int i{}, len = nums.size();

    while (nums[i] != 1) {
      if (++i == len)
        return 0;
    }

    int last_len{}, res{};
    bool gt2{};

    for (;;) {
      int cur_len{1};
      while (1) {
        if (++i == len) {
          return cur_len == len ? len - 1
                                : std::max(cur_len + (gt2 ? 0 : last_len), res);
        }
        if (nums[i] != 1)
          break;
        ++cur_len;
      }

      res = std::max(cur_len + (gt2 ? 0 : last_len), res);
      last_len = cur_len;

      gt2 = false;
      while (1) {
        if (++i == len) {
          return res;
        }
        if (nums[i] == 1)
          break;
        gt2 = true;
      }
    }
    abort();
    // return longest;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TEST(3, s.longestSubarray({1, 1, 0, 1}));
  TEST(5, s.longestSubarray({0, 1, 1, 1, 0, 1, 1, 0, 1}));
  TEST(2, s.longestSubarray({1, 1, 1}));
  return 0;
}
