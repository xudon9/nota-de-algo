#include "../../common.hpp"
#include <algorithm>
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
  static int peakIndexInMountainArray(const vector<int> &arr) {
    int l = 0, r = arr.size() - 1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (arr[mid] < arr[mid + 1])
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
