// https://leetcode.com/problems/n-ary-tree-level-order-traversal/submissions/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  void dfs(Node* root, int level, vector<vector<int>>& tree) {
    if(root == NULL) return;
    level++;

    if(tree.size() < level) {
      vector<int> vec;
      tree.push_back(vec);
    }
    tree[level-1].push_back(root->val);
    for(int i = 0; i < root->children.size(); i++) {
      dfs(root->children[i], level, tree);
    }
  }
  
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> tree; 

    dfs(root, 0, tree);

    return tree;
  }
};