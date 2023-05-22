#include "../../common.hpp"
#include <queue>
#include <unordered_map>

class Solution {
public:
  static vector<int> topKFrequent(vector<int> &nums, int k) {
    std::unordered_map<int, int> m;
    using P = std::pair<int, int>;
    for (int v : nums)
      ++m[v];
    // auto comparer = [](const P& p1, const P& p2) { return p1.second <
    // p2.second; };
    std::priority_queue<P> q;
    for (auto p : m) {
      q.push(make_pair(p.second, p.first));
    }
    std::vector<int> result;
    for (int i = 0; i < k; ++i) {
      result.push_back(q.top().second);
      q.pop();
    }
    return result;
  }
};
