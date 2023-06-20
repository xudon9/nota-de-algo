#include "../../common.hpp"
// https://leetcode.com/problems/k-radius-subarray-averages

auto fastio = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  static vector<int> getAverages(vector<int> &nums, int k) {
    if (k == 0)
      return std::move(nums);
    int n = nums.size() - 2 * k;
    if (n <= 0)
      return vector<int>(nums.size(), -1);
    vector<int> res;
    res.reserve(nums.size());
    res.resize(k, -1);
    auto beg = nums.begin(), end = beg + 2 * k;
    auto sum = std::accumulate(beg, end, 0ll);
    for (int i = 0; i < n; ++i) {
      sum += *end++;
      res.push_back(sum / (2 * k + 1));
      sum -= *beg++;
    }
    res.resize(nums.size(), -1);
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
