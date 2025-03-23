#include "../../common.hpp"

// https://leetcode.com/problems/count-the-number-of-complete-components/

struct Solution {
  struct Node { int parent; int depth; int n_node; int n_edge; };
  using R = vector<Node>;

  static void debug_r(const R& r) {
    int i{};
    for (const auto &n : r) {
      printf("%d: parent=%2d depth=%d root=%d\n", i, n.parent, n.depth, find_root(r, i));
      ++i;
    }
    printf("\n");
  }

  static int find_root(const R &repr, int index) {
    int cur = index;
    while (repr[cur].parent >= 0) {
      cur = repr[cur].parent;
    }
    return cur;
  }

  static void merge(R &repr, int x, int y)  {
    int rx = find_root(repr, x);
    int ry = find_root(repr, y);
    if (rx != ry) {
      if (repr[rx].depth < repr[ry].depth) {
        std::swap(rx, ry);
      }
      repr[ry].parent = rx;
      repr[rx].depth = std::max(repr[rx].depth, 1 + repr[ry].depth);
      repr[rx].n_node += repr[ry].n_node;
      repr[rx].n_edge += 1 + repr[ry].n_edge;
    } else {
      repr[rx].n_edge += 1;
    }
  }

  static int countCompleteComponents(int n, const vector<vector<int>>& edges) {
    vector<Node> group(n, {-1, 0, 1, 0});

    for (auto& vpair : edges) {
      merge(group, vpair[0],vpair[1]);
      // debug_r(group);
    }

    int result{};
    for (const Node& n : group) {
      if (n.parent < 0 && n.n_node * (n.n_node - 1) / 2 == n.n_edge)
        ++result;
    }
    return result;
  }
};

int main (int argc, char *argv[]) {
  Solution s;
  auto result = s.countCompleteComponents(6, {{0,1},{0,2},{1,2},{3,4},{3,5}});
  DEBUG(result);
  return 0;
}
