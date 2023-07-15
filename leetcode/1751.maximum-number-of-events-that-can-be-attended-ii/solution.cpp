#include "../../common.hpp"
#include <algorithm>

//  https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
// #define DEBUG(...)
#define IRANGE(var) (var).begin(), (var).end()

struct Solution {
  enum Label { startTime, endTime, value };

  static int test(const vector<vector<int>> &events, int k) {
    vector<vector<int>> e = events;
    return maxValue(e, k);
  }

  static int maxValue(vector<vector<int>> &events, int k) {
    auto cmp = [](const vector<int> &t1, const vector<int> &t2) {
      return t1[startTime] < t2[startTime];
    };
    std::sort(IRANGE(events), cmp);
    const int len = events.size();
    vector<vector<int>> dp(len);
    vector<int> tmpKey{0};
    auto eventsBeg = events.cbegin(), eventsEnd = events.cend();
    dp.back().push_back(events.back()[value]);
    DEBUG(dp.back());
    for (int i = len - 2; i >= 0; --i) {
      int vi = events[i][value];
      int nextStart = events[i][endTime];
      tmpKey[0] = nextStart;
      auto it = std::upper_bound(eventsBeg + i + 1, eventsEnd, tmpKey, cmp);
      int ni = it - eventsBeg;
      auto &dpi = dp[i], &dpp = dp[i + 1];
      if (ni == len) {
        DEBUG("NOT found");
        dpi.push_back(std::max(dpp[0], vi));
        for (int c = 1; c < dpp.size(); ++c) {
          dpi.push_back(dpp[c]);
        }
      } else {
        auto &dpn = dp[ni];
        dpi.push_back(std::max(dpp[0], vi));
        DEBUG("FOUND", ni, dpn);
        for (int c = 1; c < std::min({dpn.size() + 1, dpp.size(), (size_t)k});
             ++c) {
          DEBUG(c, dpp[c], vi + dpn[c - 1]);
          dpi.push_back(std::max(dpp[c], vi + dpn[c - 1]));
        }
        while (dpi.size() < dpp.size()) {
          dpi.push_back(dpp[dpi.size()]);
        }
        if (dpi.size() < k)
          dpi.push_back(vi + dpn.back());
      }
      DEBUG(dpi);
    }
    return *std::max_element(IRANGE(dp.front()));
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  // clang-format off
  TEST(7, s.test({{1, 2, 4}, {3, 4, 3}, {2, 3, 1}}, 2));
  TEST(10, s.test({{1, 2, 4}, {3, 4, 3}, {2, 3, 10}}, 2));
  TEST(9, s.test({{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}}, 3));
  TEST( 151,
      s.test({
       {5, 62, 67}, 
       {11, 17, 56}, 
       {24, 40, 53}, 
       {56, 89, 15}, 
       {66, 69, 84}
       }, 2));
  // clang-format on
  return 0;
}
