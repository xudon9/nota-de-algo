#include "../../common.hpp"
#include <algorithm>
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class Solution {
public:
  static int minSpeedOnTime(const vector<int> &dist, double hour) {
    if (dist.size() - 1 >= hour) {
      return -1;
    }

    int l = 1, r = *std::max_element(dist.begin(), dist.end() - 1);
    r = std::max(r, 1 + (int)(dist.back() / (hour - dist.size() + 1)));

    auto ok = [&](int speed) {
      double sum = 0;
      int i = 0;
      for (int d : dist) {
        if (i < dist.size() - 1)
          sum += d / speed + (d % speed != 0);
        else
          sum += d / (double)speed;
        ++i;
      }
      return sum <= hour;
    };
    while (l < r) {
      int m = (l + r) / 2;
      if (ok(m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TEST(s.minSpeedOnTime({1, 3, 2}, 6), 1);
  TEST(s.minSpeedOnTime({1, 3, 2}, 2.7), 3);
  TEST(s.minSpeedOnTime({1, 3, 2}, 1.9), -1);
  TEST(s.minSpeedOnTime({1, 1, 100000}, 2.01), 10000000);
  return 0;
}
