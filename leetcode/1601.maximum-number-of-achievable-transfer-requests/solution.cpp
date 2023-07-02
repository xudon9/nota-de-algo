#include "../../common.hpp"
#include <cstring>
// auto fastio {{}(){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

struct Solution {
  static int maximumRequests(int nbuild, const vector<vector<int>> &requests) {
    size_t ans{};
    int8_t degree[nbuild];
    size_t max = 1 << requests.size();
    for (size_t i{}; i < max; i += 1) {
      std::bitset<16> bs(i);
      auto n = bs.count();
      if (n >= ans) {
        std::fill(degree, degree + nbuild, '\0');
        for (auto &p : requests) {
          if (bs.test(&p - requests.data())) {
            --degree[p[0]];
            ++degree[p[1]];
          }
        }
        if (std::all_of(degree, degree + nbuild, [](auto n) { return !n; }))
          ans = n;
      }
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TEST(5,
       s.maximumRequests(5, {{0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}}));
  TEST(3, s.maximumRequests(3, {{0, 0}, {1, 2}, {2, 1}}));
  TEST(4, s.maximumRequests(4, {{0, 3}, {3, 1}, {1, 2}, {2, 0}}));
  return 0;
}
