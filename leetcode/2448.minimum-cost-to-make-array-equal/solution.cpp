#include "../../common.hpp"
auto fastio = []() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  return nullptr;
}();
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/

class Solution {
public:
  static int64_t minCost(vector<int> &nums, vector<int> &price) {
    vector<int> indices(nums.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(),
              [&](int i, int j) { return nums[i] < nums[j]; });
    // Get cost based on smallest num
    auto it{indices.cbegin()}, ite{indices.cend()};
    int64_t total_cost{};
    for (int smallest{nums[*it++]}; it != ite; ++it) {
      total_cost += (nums[*it] - smallest) * (int64_t)price[*it];
    }
    // Calculate sum of price[i] for all i
    int64_t sum_price{std::reduce(price.begin(), price.end(), 0ll)};
    int64_t prev_price_sum{price[indices.front()]};
    int64_t min_cost{total_cost};
    // DEBUG(min_cost);
    for (it = indices.cbegin() + 1; it != ite; ++it) {
      int delta = nums[*it] - nums[*(it - 1)];
      total_cost += (2 * prev_price_sum - sum_price) * delta;
      prev_price_sum += price[*it];
      min_cost = std::min(min_cost, total_cost);
      // DEBUG(total_cost);
    }
    return min_cost;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> nums{1, 3, 5, 2}, cost{2, 3, 1, 14};
  DEBUG(Solution::minCost(nums, cost));
}
