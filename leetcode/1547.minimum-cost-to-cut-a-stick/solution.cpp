#include "../../common.hpp"

// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

class Solution {
  using K = std::pair<uint8_t, uint8_t>;
  using V = int;

  std::map<K, V> cache;
  vector<int> cuts;

  V go(K key) {
    auto [i1, i2] = key;
    if (i1 + 1 == i2)
      return 0;
    auto [it, ite] = cache.equal_range(key);
    if (it != ite)
      return it->second;
    int min_cost = INT_MAX;
    for (int i = i1 + 1; i != i2; ++i) {
      int sub = go({i1, i}) + go({i, i2});
      min_cost = std::min(min_cost, sub);
    }
    min_cost += cuts[i2] - cuts[i1];
    cache.emplace_hint(it, key, min_cost);
    return min_cost;
  }

public:
  int minCost(int n, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    auto len = (uint8_t)cuts.size();
    std::sort(cuts.begin(), cuts.end());
    this->cuts = std::move(cuts);
    cache.clear();
    return go({0, len - 1});
  }
};

int main()
{
  int n = 9;
  vector<int> cuts = {5,6,1,4,2};
  Solution s;
  DEBUG(s.minCost(n, cuts));
}
