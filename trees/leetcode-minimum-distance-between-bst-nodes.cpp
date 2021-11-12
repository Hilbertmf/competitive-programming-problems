// https://leetcode.com/problems/minimum-distance-between-bst-nodes/submissions/
#define INF (int)1e9;
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
  void inOrder(TreeNode* root, vector<int>& nodes) {
    if(root == NULL)
      return;
    if(root->left != NULL)
      inOrder(root->left, nodes);
    
    nodes.push_back(root->val);

    if(root->right != NULL)
      inOrder(root->right, nodes);
  }
  
  int minDiffInBST(TreeNode* root) {
    vector<int> nodes;
    inOrder(root, nodes);
    int dist = INF;
    for(int i = 1; i < nodes.size(); i++) {
      dist = min(dist, nodes[i] - nodes[i-1]);
    }
    return dist;
  }
};