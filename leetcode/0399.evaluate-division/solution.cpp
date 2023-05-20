/* https://leetcode.com/problems/evaluate-division/ */

#include "../../common.hpp"

#include <queue>
#include <set>

class Solution {
public:
  static vector<double> calcEquation(vector<vector<string>> &equations,
                                     vector<double> &values,
                                     vector<vector<string>> &queries) {
    map<string, vector<std::pair<string, double>>> graph;

    for (int i = 0; i < equations.size(); ++i) {
      auto &src = equations[i][0];
      auto &dst = equations[i][1];
      double ratio = values[i];

      graph[src].emplace_back(dst, ratio);
      graph[dst].emplace_back(src, 1 / ratio);
    }

    vector<double> result;
    result.reserve(queries.size());

    for (auto &query : queries) {
      std::set<string> visited;
      std::queue<std::pair<string, double>> q;

      const string &src = query[0];
      const string &dst = query[1];
      double new_val = -1.0;

      if (graph.find(src) != graph.end()) {
        q.emplace(query[0], 1.0);
        visited.insert(query[0]);

        while (!q.empty()) {
          auto [node, factor] = std::move(q.front());
          q.pop();

          if (node == dst) {
            new_val = factor;
            break;
          }

          for (auto [adj, mult] : graph[node]) {
            bool inserted = visited.insert(adj).second;
            if (!inserted)
              continue;
            q.emplace(adj, mult * factor);
          }
        }
      }
      result.push_back(new_val);
    }

    return result;
  }
};

int main() {
  vector<vector<string>> v{{"a", "b"}, {"a", "c"}},
      q{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}, {"b", "c"}};
  vector<double> values{2., 3.};
  auto r = Solution::calcEquation(v, values, q);
  DEBUG(r);
}
