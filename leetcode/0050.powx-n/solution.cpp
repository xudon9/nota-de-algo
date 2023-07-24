#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/powx-n/

struct Solution {
  static double myPow(double x, int n) {
    double r = 1.0;
    while (n) {
      auto m = n % 2;
      if (m == 1) {
        r *= x;
        --n;
      } else if (m == -1) {
        r /= x;
        ++n;
      } else {
        x = x * x;
        n /= 2;
      }
    }
    return r;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
