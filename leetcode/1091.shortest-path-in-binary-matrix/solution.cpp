#include "../../common.hpp"

class Solution {
  using L = std::pair<int8_t, int8_t>;

public:
  static int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    const int n = grid.size();
    std::queue<L> q;
    if (grid[0][0])
      return -1;
    q.emplace(0, 0);
    grid[0][0] = 1;
    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      int cost = grid[r][c];
      DEBUG((int)r, (int)c, cost);
      if (r + 1 == n && c == r) {
        return cost;
      }

#define C(rexp, cexp, cond)                                                    \
  if (int8_t r2 = r + (rexp), c2 = c + (cexp); (cond) && !grid[r2][c2]) {      \
    q.emplace(r2, c2);                                                         \
    grid[r2][c2] = cost + 1;                                                   \
  }

      C(-1, -1, r2 >= 0 && c2 >= 0);
      C(-1, 0, r2 >= 0);
      C(-1, 1, r2 >= 0 && c2 < n);
      C(0, -1, c2 >= 0);
      // C(0,0, true);
      C(0, 1, c2 < n);
      C(1, -1, r2 < n && c2 >= 0);
      C(1, 0, r2 < n);
      C(1, 1, r2 < n && c2 < n);
    }

    return -1;
  }
};

int main() {
  vector<vector<int>> v;
  v.push_back({1, 0, 0});
  v.push_back({1, 1, 0});
  v.push_back({1, 1, 0});
  auto c = Solution::shortestPathBinaryMatrix(v);
  DEBUG(c);
}
