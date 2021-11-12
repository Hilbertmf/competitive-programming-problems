#include <bits/stdc++.h>
using namespace std;
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
// we've gotta populate a stack in descending order
// in order to do that we have to traverse the bst in reverse order
// reverse order: right, curr, left
class BSTIterator {
public:
  std::stack<int> stack;
  
  void reverseOrder(TreeNode* root, std::stack<int>& stack) {
    if(root == NULL)
      return;
    reverseOrder(root->right, stack);
    stack.push(root->val);
    reverseOrder(root->left, stack);
  }
  
  BSTIterator(TreeNode* root) {
    reverseOrder(root, stack);
  }

  int next() {
    int next = stack.top();
    stack.pop();
    return next;
  }

  bool hasNext() {
    return !stack.empty();
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */