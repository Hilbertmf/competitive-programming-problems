// https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/
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
  void traverseBST(TreeNode* root, TreeNode* node, int val) {
    if(val > root->val) {
      if(root->right != nullptr)
        traverseBST(root->right, node, val);
      else {
        root->right = node;
        return;
      }
    }
    else {
      if(root->left != nullptr) 
        traverseBST(root->left, node, val);
      else {
        root->left = node;
        return;
      }
    }
  }

  TreeNode* insertIntoBST(TreeNode* root, int val) {
    struct TreeNode* node = new TreeNode();
    node->val = val;
    if(root == nullptr)
      root = node;
    else
      traverseBST(root, node, val);

    return root;
  }
};