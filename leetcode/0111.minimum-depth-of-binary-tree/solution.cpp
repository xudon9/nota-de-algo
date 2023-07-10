#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/minimum-depth-of-binary-tree/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct Solution {
  static int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    int lhs = root->left ? minDepth(root->left) : 0;
    int rhs = root->right ? minDepth(root->right) : 0;
    return 1 + (lhs && rhs ? std::min(lhs, rhs) : lhs + rhs);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
