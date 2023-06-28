#include "../../common.hpp"
auto fastio{[]() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  return nullptr;
}()};
// https://leetcode.com/problems/path-with-maximum-probability/

struct Solution {
  using State = std::pair<double, short>;
  static double maxProbability(int n, const vector<vector<int>> &edges,
                               const vector<double> &succProb, int start,
                               int end) {
    std::map<short, vector<std::pair<short, double>>> adj;
    double dist[n];
    std::fill(dist, dist + n, -std::numeric_limits<double>::infinity());
    dist[start] = 0;
    for (int i{}; i < edges.size(); ++i) {
      const auto &p = edges[i];
      short n1 = p[0], n2 = p[1];
      double logp = std::log(succProb[i]);
      if (!std::isinf(logp)) {
        adj[n1].emplace_back(n2, logp);
        adj[n2].emplace_back(n1, logp);
      }
    }
    std::priority_queue<State> heap;
    heap.push({0, start});
    while (!heap.empty()) {
      auto [prob, pos] = heap.top();
      if (pos == end)
        return std::exp(prob);
      // DEBUG(std::exp(prob), pos);
      heap.pop();

      if (prob < dist[pos])
        continue;

      for (const auto &np : adj[pos]) {
        // printf("checking %d->%d %lf\n", pos, np.first, std::exp(np.second));
        auto new_p = np.second + prob;
        if (new_p > dist[np.first]) {
          // std::printf("\tUpdating %d to %lf\n", np.first, std::exp(new_p));
          heap.push({new_p, np.first});
          dist[np.first] = new_p;
        }
      }
    }
    return 0;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  // TEST(s.maxProbability(3, {{0, 1}, {1, 2}, {0, 2}}, {.5, .5, .2}, 0, 2),
  // .25); TEST(s.maxProbability(3, {{0, 1}, {1, 2}, {0, 2}}, {.5, .5, .3}, 0,
  // 2), .3); TEST(s.maxProbability(3, {{0, 1}}, {.5}, 0, 2), .0);

  TEST(s.maxProbability(5, {{1, 4}, {2, 4}, {0, 4}, {0, 3}, {0, 2}, {2, 3}},
                        {0.37, 0.17, 0.93, 0.23, 0.39, 0.04}, 3, 4),
       .2139);
  return 0;
}
