#include "../../common.hpp"

// https://leetcode.com/problems/number-of-provinces/
#define MAX_N 200

class Solution {
  static int find0(const std::bitset<MAX_N> &bs, int n) {
    for (int i = 0; i < n; ++i) {
      if (!bs[i])
        return i;
    }
    return n;
  }

public:
  static int findCircleNum(vector<vector<int>> &isConnected) {
    const int n = isConnected.size();
    std::bitset<MAX_N> visited;
    std::vector<int> stack;
    stack.reserve(n);
    auto push = [&](int n) {
      stack.push_back(n);
      visited.set(n);
    };
    auto pop = [&]() -> int {
      int top = stack.back();
      stack.pop_back();
      return top;
    };
    int result = 0, repr;
    while ((repr = find0(visited, n)) < n) {
      // DEBUG(repr);
      ++result;

      stack.clear();
      push(repr);
      while (!stack.empty()) {
        int node = pop();
        // DEBUG(node, stack);

        for (int adj = 0; adj < n; ++adj) {
          if (!visited[adj] && isConnected[node][adj])
            push(adj);
        }
      }
    }
    return result;
  }
};

int main() {
  vector<vector<int>> m = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  auto b = Solution::findCircleNum(m);
  DEBUG(m, b);
}
