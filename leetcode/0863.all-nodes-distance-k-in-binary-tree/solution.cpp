#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x, TreeNode *l = 0, TreeNode *r = 0)
      : val(x), left(l), right(r) {}
  ~TreeNode() {
    if (left)
      delete left;
    if (right)
      delete right;
  }
};

struct Solution {
  struct ParentInfo {
    ParentInfo *parent;
    TreeNode *node;
    ParentInfo(TreeNode *n, ParentInfo *p = nullptr) : parent(p), node(n) {}
  };

  static void add_childrens(vector<int> &result, TreeNode *node, int remain) {
    if (!node)
      return;
    if (!remain)
      result.push_back(node->val);
    else {
      --remain;
      if (node->left)
        add_childrens(result, node->left, remain);
      if (node->right)
        add_childrens(result, node->right, remain);
    }
  }

  static void search_and_set(vector<int> &result, TreeNode *target, int k,
                             ParentInfo *pi, TreeNode *node) {
    if (node == target) {
      TreeNode *child = node;
      ParentInfo *cur = pi;
      int rem = k - 1;
      while (rem && cur) {
        TreeNode *par = cur->node;
        --rem;
        if (par->left && par->left != child) {
          add_childrens(result, par->left, rem);
        } else if (par->right && par->right != child) {
          add_childrens(result, par->right, rem);
        }
        child = par;
        cur = cur->parent;
      }
      if (rem == 0 && cur) {
        DEBUG("ok");
        result.push_back(cur->node->val);
      }
    } else {
      ParentInfo p(node, pi);
      if (node->left)
        search_and_set(result, target, k, &p, node->left);
      if (node->right)
        search_and_set(result, target, k, &p, node->right);
    }
  }

  static vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    vector<int> result;
    add_childrens(result, target, k);
    search_and_set(result, target, k, nullptr, root);
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *tg = new TreeNode(
      5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4)));
  TreeNode *t1 =
      new TreeNode(3, tg, new TreeNode(1, new TreeNode(0), new TreeNode(8)));
  DEBUG(s.distanceK(t1, tg, 2));
  delete t1;
  return 0;
}
