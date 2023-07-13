#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/find-eventual-safe-states/

struct Solution {
  static vector<int> eventualSafeNodes(const vector<vector<int>> &graph) {
    int n = graph.size();
    vector<std::pair<vector<int>, int>> reverse(n);
    for (int src = 0; src < n; ++src) {
      for (int dst : graph[src]) {
        reverse[dst].first.push_back(src);
        ++reverse[src].second;
      }
    }
    std::queue<int> worklist;
    std::vector<int> result;
    for (int node = 0; node < n; ++node) {
      if (reverse[node].second == 0) {
        worklist.push(node);
      }
    }

    while (!worklist.empty()) {
      int node = worklist.front();
      worklist.pop();
      result.push_back(node);

      auto &r = reverse[node];
      for (int n : r.first) {
        if (--reverse[n].second == 0) {
          worklist.push(n);
        }
      }
    }

    std::sort(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TEST((vector<int>{2, 4, 5, 6}),
       s.eventualSafeNodes({{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}}));
  TEST((vector<int>{4}),
       s.eventualSafeNodes({{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}}));
  return 0;
}
