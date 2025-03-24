#include "../../common.hpp"
#include <climits>
#include <utility>

#define MOD 1000000007

struct Solution {
  struct NodeInfo {
    long minDist;
    int oldcnt, cnt;
    // NodeInfo() : minDist{LONG_MAX}, oldcnt{0}, cnt(0) {}
    // NodeInfo(long d, int c) : minDist{d}, oldcnt{0}, cnt(c) {}
  };
  static int countPaths(int n, const vector<vector<int>> &roads) {
    vector<vector<std::pair<int, int>>> graph(n);
    for (auto &e : roads) {
      int src = e[0], dst = e[1], cost = e[2];
      graph[src].emplace_back(dst, cost);
      graph[dst].emplace_back(src, cost);
    }
    // DEBUG(graph);
    vector<NodeInfo> ds(n, {LONG_MAX, 0, 0});
    ds[0].minDist = 0;
    ds[0].cnt = 1;
    std::set<int> ws;
    ws.insert(0);
    while (!ws.empty()) {
      // pop one element out
      int i = *ws.begin();
      ws.erase(ws.begin());

      auto iDist = ds[i].minDist;
      auto iCnt = ds[i].cnt;
      auto iOld = ds[i].oldcnt;
      ds[i].oldcnt = iCnt;

      for (auto [j, c] : graph[i]) {
        if (j == 0)
          continue;
        // DEBUG(i, j, iDist, c);
        auto d = iDist + c;
        if (d == ds[j].minDist) {
          int delta = iCnt - iOld;
          (ds[j].cnt += delta) %= MOD;
          ws.insert(j);
        } else if (d < ds[j].minDist) {
          ds[j] = {d, 0, iCnt};
          ws.insert(j);
        }
      }
      // DEBUG(i, ws);
      // if (0) {
      //   for (int i{}; i < ds.size(); ++i) {
      //     printf("To %d minCost = %ld, numPaths = %d -> %d\n", i,
      //     ds[i].minDist,
      //            ds[i].oldcnt, ds[i].cnt);
      //   }
      //   puts("");
      // }
    }

    return ds[n - 1].cnt;
  }
};

int main() {
  if (1) {
    // Case 1
    int n = 7;
    vector<vector<int>> x = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
                             {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1},
                             {0, 4, 5}, {4, 6, 2}};
    DEBUG(Solution::countPaths(n, x));
  }
  if (1) {
    int n = 2;
    vector<vector<int>> x = {{1, 0, 10}};
    DEBUG(Solution::countPaths(n, x));
  }

  if (1) {
    int n = 200;
    vector<vector<int>> x;
    for (int i = 0; i < 199; ++i) {
      vector<int> e;
      e.push_back(i);
      e.push_back(i + 1);
      e.push_back(1000000000);
      x.push_back(e);
    }
    DEBUG(Solution::countPaths(n, x));
  }

  if (1) {
    int n = 6;
    vector<vector<int>> x{{3, 0, 4}, {0, 2, 3}, {1, 2, 2}, {4, 1, 3}, {2, 5, 5},
                          {2, 3, 1}, {0, 4, 1}, {2, 4, 6}, {4, 3, 1}};
    DEBUG(Solution::countPaths(n, x));
  }
}
