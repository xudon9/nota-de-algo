#include "../../common.hpp"

size_t max_len1 = 0;
size_t max_len2 = 0;

// https://leetcode.com/problems/make-array-strictly-increasing
class Solution {
public:
  static int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
    std::sort(arr2.begin(), arr2.end());
    vector<std::pair<int, int>> prev{{0, -1}};

    for (int now_val : arr1) {
      vector<std::pair<int, int>> curr;
      for (auto [last_mod, last_val] : prev) {
        // auto [last_mod, last_val] = last_mod_val;
        if (last_val < now_val) {
          if (!curr.empty() && curr.back().first == last_mod)
            curr.back().second = std::min(curr.back().second, now_val);
          else
            curr.emplace_back(last_mod, now_val);
        }
        if (auto it = std::upper_bound(arr2.begin(), arr2.end(), last_val);
            it != arr2.end())
          curr.emplace_back(last_mod + 1, *it);
      }
      max_len1 += curr.size();
      prev = std::move(curr);
    }
    return prev.empty() ? -1 : prev.front().first;
  }
};

// https://leetcode.com/problems/make-array-strictly-increasing
class Solution2 {
public:
  static int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
    std::sort(arr2.begin(), arr2.end());
    vector<std::pair<int, int>> prev{{0, -1}};

    for (int now_val : arr1) {
      vector<std::pair<int, int>> curr;
      for (auto [last_mod, last_val] : prev) {
        // auto [last_mod, last_val] = last_mod_val;
        if (last_val < now_val) {
          if (!curr.empty() && curr.back().first == last_mod)
            curr.back().second = std::min(curr.back().second, now_val);
          else
            curr.emplace_back(last_mod, now_val);
        }
        if (auto it = std::upper_bound(arr2.begin(), arr2.end(), last_val);
            it != arr2.end() && (curr.empty() || curr.back().second > *it))
          curr.emplace_back(last_mod + 1, *it);
      }
      // DEBUG(curr);
      max_len2 += curr.size();
      prev = std::move(curr);
    }
    return prev.empty() ? -1 : prev.front().first;
  }
};

int main() {
  srand(0);
  // vector<int> v1{1, 5, 3, 6, 7}, v2{1, 3, 2, 4};
  // vector<int> v1{1, 5, 3, 6, 7}, v2{1, 3, 4};
  // vector<int> v1{1, 5, 3, 6, 7}, v2{1, 6, 3, 3};
  vector<int> v1, v2;

  for (int t = 0; t < 100; ++t) {
    for (int i = 0; i < 5000; ++i) {
      v1.push_back(rand() % 10000);
    }
    for (int i = 0; i < 50; ++i) {
      v2.push_back(rand() % 10000);
    }
    auto n1 = Solution::makeArrayIncreasing(v1, v2);
    auto n2 = Solution2::makeArrayIncreasing(v1, v2);
    assert(n1 == n2);
  }
  DEBUG(max_len1, max_len2);
}
