#include "../../common.hpp"

/* https://leetcode.com/problems/maximum-subsequence-score/ */

class Solution {
public:
  static long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> indices, q;
    indices.reserve(nums1.size());
    q.reserve(k);
    for (int i = 0; i < nums1.size(); ++i)
      indices.push_back(i);
    std::sort(indices.begin(), indices.end(),
              [&nums2](int i, int j) { return nums2[i] > nums2[j]; });

    DEBUG(indices);

    long long s = 0, ret = -99999;
    for (int i : indices) {
      if (q.size() < k) {
        q.push_back(nums1[i]);
        std::push_heap(q.begin(), q.end(), std::greater<int>());
        s += nums1[i];

        if (q.size() == k) {
          ret = s * nums2[i];
        }
      } else if (int d = nums1[i] - q.front(); d > 0) {
        std::pop_heap(q.begin(), q.end(), std::greater<int>());
        q.back() = nums1[i];
        std::push_heap(q.begin(), q.end(), std::greater<int>());
        s += d;

        ret = std::max(ret, s * nums2[i]);
      }
    }

    return ret;
  }
};

int main() {
  std::vector<int> nums1 {1,3,3,2};
  std::vector<int> nums2{2,1, 3,4};

  std::vector<int> nums3{4, 2, 3, 1, 1};
  std::vector<int> nums4 { 7, 5, 10, 9, 6 };

  DEBUG(Solution::maxScore(nums1, nums2, 3));
  DEBUG(Solution::maxScore(nums3, nums4, 1));
}
