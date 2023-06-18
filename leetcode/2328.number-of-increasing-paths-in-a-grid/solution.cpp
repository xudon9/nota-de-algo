#include "../../common.hpp"
// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/

struct Solution {
  static const int mod = 1e9 + 7;

  struct Info {
    bool visited : 1;
    unsigned count : 31;
  };

#define GET(i, j) (buf[(i)*nCol + (j)])

  static int dfs(vector<vector<int>> &grid, Info *buf, short nRow, short nCol,
                 short i, short j) {
    auto &e{GET(i, j)};
    if (e.visited)
      return e.count;

    int total{1};
#define CHECK(boundPred, in, jn)                                               \
  if ((boundPred) && grid[in][jn] < grid[i][j]) {                              \
    total = (total + dfs(grid, buf, nRow, nCol, in, jn)) % mod;                \
  }
    CHECK(i > 0, i - 1, j);
    CHECK(i + 1 < nRow, i + 1, j);
    CHECK(j > 0, i, j - 1);
    CHECK(j + 1 < nCol, i, j + 1);
    e.visited = true;
    return e.count = total;
  }

  static int countPaths(vector<vector<int>> &grid) {
    const int nRow = grid.size(), nCol = grid[0].size(), nCell{nRow * nCol};
    Info *const buf = new Info[nCell];
    std::memset(buf, 0, nCell * sizeof buf[0]);
    int result{};
    for (int i{}; i < nRow; ++i)
      for (int j{}; j < nCol; ++j)
        result = (result + dfs(grid, buf, nRow, nCol, i, j)) % mod;
#undef GET
#undef CHECK
    delete[] buf;
    return result;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> grid1{{1, 1}, {3, 4}};
  std::vector<std::vector<int>> grid2{{1}, {2}};
  Solution s;
  auto n1 = s.countPaths(grid1);
  DEBUG(n1);
  auto n2 = s.countPaths(grid2);
  DEBUG(n2);
  DEBUG(sizeof(Solution::Info));
  return 0;
}
