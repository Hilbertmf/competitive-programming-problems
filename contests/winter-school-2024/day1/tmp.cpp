#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int num_a = count(s.begin(), s.end(), 'a');
        int num_b = count(s.begin(), s.end(), 'b');
        int ans = min(num_a, num_b);

        stack<int> first_b, last_a;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if (s[i] == 'a')
                last_a.push(i);
        }
        for(int i = n - 1; i >= 0; --i) {
            if (s[i] == 'b')
                first_b.push(i);
        }

        int count = 0;
        while (!first_b.empty() && !last_a.empty() &&
               first_b.top() < last_a.top()) {
            
        }

    }
};


int main() {
    vector<int> test1 {2,5,3,4,1};
    int out1 = 3;
    vector<int> test2 {2,1,3};
    int out2 = 0;
    vector<int> test3 {1,2,3,4};
    int out3 = 4;

    auto sol1 = new Solution();
    int ans1 = sol1->numTeams(test1);
    if(ans1 == out1) {
        cout << "test1: Correct!" << "\n";
    }
    else {
        cout << "test1: Wrong!" << "\n";
        
    }

    auto sol2 = new Solution();
    int ans2 = sol2->numTeams(test2);
    if(ans2 == out2) {
        cout << "test2: Correct!" << "\n";
    }
    else {
        cout << "test2: Wrong!" << "\n";        
    }

    auto sol3 = new Solution();
    int ans3 = sol3->numTeams(test3);
    if(ans3 == out3) {
        cout << "test3: Correct!" << "\n";
    }
    else {
        cout << "test3: Wrong!" << "\n";
        
    }

}



class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n);

        int curr_w = 0;

        for(int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                dp[i] = books[i][1];
                curr_w += books[i][0];
            }
            else {

            }
        }
    }
};


class Solution {
public:
    void getDepths(TreeNode* root, map<TreeNode*, int>& depths, int d) {
        depths[root] = d;
        if (root->left)
            getDepths(root->left, depths, d + 1);
        if (root->right)
            getDepths(root->right, depths, d + 1);
    }
    void getParents(TreeNode* root, map<TreeNode*, TreeNode*>& parent,
    TreeNode* par) {
        parent[root] = par;
        if (root->left)
            getParents(root->left, parent, root);
        if (root->right)
            getParents(root->right, parent, root);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, int> depth;
        map<TreeNode*, TreeNode*> parent_node;
        // anc[i][j] => 2^j ancestral of ith node
        // anc[i][0] => 2^0 = 1 ancestral or parent of i
        // anc[i][1] => 2^1 = 2 ancestral or parent of i
        // anc[i][2] => 2^2 = 4 ancestral or parent of i
        // anc[i][3] => 2^3 = 8 ancestral or parent of i
        getDepths(root, depth, 0);
        getParents(root, parent_node, nullptr);
        parent_node[root] = root;

        int MAX = 0;
        for(auto &[k, v] : parent_node) {
            MAX = max(MAX, k->val);
            if (k != root) MAX = max(MAX, v->val);
        }

        vector<int> par(MAX + 1);
        for(auto &[k, v] : parent_node) {
            if (k == root) continue;
            par[k->val] = v->val;
        }
        par[root->val] = -1;

        int LOG = 0;
        int d = 0;
        for(auto &[k, v] : depth) {
            d = max(d, v);
        }
        while ((1 << LOG) < d) {
            LOG++;
        }

        int anc[MAX][LOG];

        
        for(auto &[child, p] : parent_node) {
            anc[child->val][0] = p->val;
        }

        for(int j = 1; j < LOG; ++j) {
            for(int i = 0; i <= MAX; ++i) {
                anc[i][j] = anc[ anc[i][j - 1] ][j - 1];
            }
        }

        int a = p->val, b = q->val;

        for(int i = LOG - 1; i >= 0; --i) {
            if (anc[a][i] != anc[b][i]) {
                a = anc[a][i];
                b = anc[b][i];
            }
        }

        cout << par[a];
        return p;
    }
};