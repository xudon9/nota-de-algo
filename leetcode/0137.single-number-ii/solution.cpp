#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/single-number-ii/

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int x{}, y{}, x0, y0;
    for (int z : nums) {
      x0 = ((~z) & x) | (z & (~x) & y);
      y0 = ((~z) & y) | (z & (~y) & (~x));
      x = x0;
      y = y0;
    }
    return y;
  }
};

int main(int argc, char *argv[]) { return 0; }
