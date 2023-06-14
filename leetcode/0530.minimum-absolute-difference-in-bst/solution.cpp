// https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/970802321/

#include "../../common.hpp"
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  struct I {
    int min, max, mindiff;
  };

public:
  static I dfs(const TreeNode *n) {
    I i{n->val, n->val, INT_MAX};
    if (n->left) {
      I li = dfs(n->left);
      i.min = li.min;
      i.mindiff = std::min(li.mindiff, n->val - li.max);
    }
    if (n->right) {
      I ri = dfs(n->right);
      i.max = ri.max;
      i.mindiff = std::min({ri.mindiff, ri.min - n->val, i.mindiff});
    }
    // printf("%d => %d %d %d\n", n->val, i.min, i.max, i.mindiff);
    return i;
  }

  static int getMinimumDifference(const TreeNode *root) {
    return dfs(root).mindiff;
  }
};
