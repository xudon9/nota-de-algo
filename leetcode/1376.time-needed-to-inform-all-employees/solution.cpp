#include "../../common.hpp"

// https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
  static int getDelay(const vector<int> &manager, const vector<int> &informTime,
                      vector<int> &delayTime, int id) {
    int &i = delayTime[id];
    if (i >= 0)
      return i;
    int m = manager[id];
    i = informTime[id] +
        (m < 0 ? 0 : getDelay(manager, informTime, delayTime, m));
    return i;
  }

public:
  static int numOfMinutes(int n, int headID, const vector<int> &manager,
                          const vector<int> &informTime) {
    vector<int> delay(n, -1);

    int m = 0;
    for (int i = 0; i < n; ++i) {
      m = std::max(m, getDelay(manager, informTime, delay, i));
    }
    return m;
  }
};

int main() {
  // int t = Solution::numOfMinutes(1, 0, {-1}, {0});
  int t = Solution::numOfMinutes(6, 2, {2,2,-1,2,2,2}, {0,0,1,0,0,0});
  DEBUG(t);
}
