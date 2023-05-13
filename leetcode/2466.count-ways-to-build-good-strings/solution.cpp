#include "../../common.hpp"

/*
 * https://leetcode.com/problems/count-ways-to-build-good-strings/
*/

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
      constexpr const auto mod = 1000000007;
      std::map<int, int> m{{0, 1}};
      int key, result = 0;

      for (auto it = m.begin(); it != m.end(); it = m.upper_bound(key)) {
        key = it->first;
        auto cnt = it->second;
        if (key >= low)
          (result += cnt) %= mod;
        if (auto k = key+zero; k <= high)
          (m[k] += cnt) %= mod;
        if (auto k = key+one; k <= high)
          (m[k] += cnt) %= mod;
      }

      return result;
    }
};

int main() {
  Solution s;
  DEBUG(s.countGoodStrings(3,3,1,1));
  DEBUG(s.countGoodStrings(2,3,1,2));
}
