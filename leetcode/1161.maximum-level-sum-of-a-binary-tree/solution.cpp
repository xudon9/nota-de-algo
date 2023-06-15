// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static int maxLevelSum(TreeNode* root) {
      std::vector<TreeNode*> cur(1, root), next;
      int max_sum = INT_MIN, max_level, cur_level = 1;
      while (!cur.empty()) {
        int s = 0;
        for (auto node : cur) {
          s += node->val;
          if (node->left)
            next.push_back(node->left);
          if (node->right)
            next.push_back(node->right);
        }
        if (max_sum < s) {
          max_sum = s;
          max_level = cur_level;
        }
        cur.clear();
        cur.swap(next);
        ++cur_level;
      }
      return max_level;
    }
};


