#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference

struct Solution {
  int longestSubsequence(const vector<int> &arr, int difference) {
    std::map<int, uint16_t> m;
    for (int n : arr) {
      auto it = m.find(n - difference);
      if (it == m.end()) {
        m.emplace(n, 1);
      } else {
        auto len = it->second;
        m[n] = 1 + len;
      }
    }
    int max = 0;
    for (const auto &p : m)
      max = std::max(max, (int)p.second);
    return max;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
