#include "../../common.hpp"
// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array//

class H : public std::iterator<std::random_access_iterator_tag, std::int64_t> {
  int h;

public:
  static int index, n;

  H() : h{} {}
  H(int h) : h{h} {}
  operator int &() { return h; }

  static int64_t min_area(int n, int height) {
    return n <= height ? (2 * height - n + 1) * (int64_t)(n) / 2
                       : (height + 1) * (int64_t)(height) / 2 + (n - height);
  }

  std::int64_t operator*() const {
    return min_area(index + 1, h) + min_area(n - index - 1, h - 1);
  }
};

int H::index, H::n;

class Solution {
public:
  static int maxValue(int n, int index, int maxSum) {
    H::index = index;
    H::n = n;
    return std::upper_bound(H(1), H(maxSum + 1), (int64_t)maxSum) - 1;
  }
};

int main() {
  // auto v = Solution::maxValue(4, 2, 6);
  // auto v = Solution::maxValue(6, 1, 10);
  auto v = Solution::maxValue(685453290, 293811406, 689728311);
  DEBUG(v);
}
