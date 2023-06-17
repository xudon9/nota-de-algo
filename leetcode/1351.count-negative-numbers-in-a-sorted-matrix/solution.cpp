#include "../../common.hpp"
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
  static int countNegatives(vector<vector<int>> &grid) {
    const int n_row = grid.size(), n_col = grid[0].size();
    int res{}, col{};
    for (int row = n_row - 1; row >= 0; --row) {
      while (grid[row][col] >= 0) {
        if (++col >= n_col)
          return res;
      }
      res += n_col - col;
    }
    return res;
  }
};

int main() {
  vector<vector<int>> m{
      {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
  int n = Solution::countNegatives(m);
  DEBUG(n);
}
