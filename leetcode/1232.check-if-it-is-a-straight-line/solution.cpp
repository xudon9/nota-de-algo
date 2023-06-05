#include "../../common.hpp"
// https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
  static bool checkStraightLine(vector<vector<int>> &coordinates) {
    auto it = coordinates.cbegin(), end = coordinates.cend();
    int x0 = (*it)[0], y0 = (*it)[1];
    ++it;
    int x1 = (*it)[0], y1 = (*it)[1];

    int dx = x1 - x0;
    if (dx) {
      int dy = y1 - y0;
      for (; it != end; ++it) {
        if (dx * ((*it)[1] - y0) != dy * ((*it)[0] - x0))
          return false;
      }
    } else {
      for (; it != end; ++it) {
        if ((*it)[0] != x0)
          return false;
      }
    }
    return true;
  }
};

int main() {
  vector<vector<int>> xys1 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
  vector<vector<int>> xys2 = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
  auto flag = Solution::checkStraightLine(xys2);
  DEBUG(flag);
}
