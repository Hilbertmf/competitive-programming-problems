class Node {
  public:
  std::vector<Node*> children = std::vector<Node*>(26);
  char val;

  Node() {}
  Node(char _val) {val = _val;}
};

class Trie {
public:
  Node* root;
  
  Trie() {
    root = new Node();
  }
  
  void insert(string word) {
    if(root->val == NULL) {
      root->val = word[0];
      Node* node = root;
      for(int i = 1; i < word.size(); i++) {
        Node* newNode(word[i]);
        node->children[word[i] - 'a'] = newNode;
        node = node->children[word[i] - 'a'];
      }
    }
    else {
      
    }
  }
  
  bool search(string word) {
    Node* node = root;
    if(word[0] != node->val)
      return false;
    for(int i = 1; i < word.size(); i++) {
      if(node == NULL || word[i] != node->val)
        return false;
      node = node->children[word[i] - 'a'];
    }
    return true;
  }
  
  bool startsWith(string prefix) {
    Node* node = root;
    if(word[0] != node->val)
      return false;
    for(int i = 1; i < word.size(); i++) {
      if(node == NULL || word[i] != node->val)
        return false;
      node = node->children[word[i] - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */