// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
  
  void dfs(TreeNode* root, int level, vector<vector<int>>& tree) {
    if(root == NULL) return;

    level++;
    if(tree.size() < level) {
      vector<int> vec;
      tree.push_back(vec);
    }
      
    tree[level-1].push_back(root->val);
    dfs(root->left, level, tree);
    dfs(root->right, level, tree);
  }

  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> tree;  

    dfs(root, 0, tree);
    return tree;
  }
};