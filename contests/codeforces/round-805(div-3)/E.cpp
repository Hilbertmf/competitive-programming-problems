// accepted
// https://codeforces.com/contest/1702/problem/E
// time: O(n)
// space: O(n)
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (long long)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const long long MOD = 1000000007; // 10^9 - 7 

bool bfs(int idx, vector<pair<int, int>>& dominoes, vector<list<int>>& groups, vector<int>& color) {
    color[idx] = 0;
    queue<int> qu;
    qu.push(idx);

    while (!qu.empty()) {
        int curr = qu.front();
        qu.pop();

        for(auto idx : groups[dominoes[curr].first]) {
            if(idx == curr) continue;
            if(color[idx] == -1) {
                color[idx] = color[curr] ^ 1;
                qu.push(idx);
            }
            else if(color[curr] == color[idx])
                return false;
        }
        
        for(auto idx : groups[dominoes[curr].second]) {
            if(idx == curr) continue;
            if(color[idx] == -1) {
                color[idx] = color[curr] ^ 1;
                qu.push(idx);
            }
            else if(color[curr] == color[idx])
                return false;
        }

    }

    return true;
}

int main() { 
    FASTIO;
    long long t;
    cin >> t;
    while (t--) {
        int numDominoes;
        cin >> numDominoes;
        vector<pair<int, int>> dominoes(numDominoes);
        vector<list<int>> groups(numDominoes+1);
        bool possible = true;
        for(int i = 0; i < numDominoes; ++i) {
            cin >> dominoes[i].first >> dominoes[i].second;
            if(dominoes[i].first == dominoes[i].second)
                possible = false;
            groups[dominoes[i].first].push_back(i);
            groups[dominoes[i].second].push_back(i);
        }
                    
        // neighbors of domino {i, j} are at: groups[i] and groups[j]

        vector<int> color(numDominoes, -1);

        for(int i = 0; i < numDominoes && possible; ++i) {
            if(color[i] == -1)
                possible &= bfs(i, dominoes, groups, color);
        }
        
        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }	
    
    return 0; 
}

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, // key type
null_type, // mapped-policy
less_equal<int>, // key comparison function
rb_tree_tag, // underlying data structure
tree_order_statistics_node_update>
ordered_set;
// use order_of_key and find_by_order methods
// using less_equal exchanges upper and lower bounds
// use upper bound to erase elements
// order_of_key refers to the first occurence of key

class Solution {
public:
    struct state {
        int val;
        int idx;
        bool shouldInsert;
    };

    struct segtree {
        int size;
        vector<int> sums;

        void init(int sz) {
            size = sz;
            sums = vector<int>(size * 4);
        }

        int query(int ql, int qr) {
            return query(ql, qr, 0, size - 1, 0);
        }
        int query(int ql, int qr, int l, int r, int node) {
            if(ql <= l && qr >= r)
                return sums[node];
            if(r < ql || l > qr)
                return 0;
            int mid = (l + 2) / 2;
            return query(ql, qr, l, mid, 2*node + 1) +
            query(ql, qr, mid + 1, r, 2*node + 2);
        }

        void update(int pos, int val) {
            update(pos, val, 0, size - 1, 0);
        }
        void update(int pos, int val, int l, int r, int node) {
            if(l == r)
                sums[node] = val;
            else {
                int mid = (l + r) / 2;
                if(pos <= mid) {
                    update(pos, val, l, mid, 2*node + 1);
                }
                else {
                    update(pos, val, mid + 1, r, 2*node + 2);
                }
                sums[node] = sums[2*node + 1] + sums[2*node + 2];
            }
        }
    };

    int reversePairs(vector<int>& nums) {
        vector<state> states;
        segtree tree;
        tree.init(nums.size());
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            states.push_back((state){nums[i], i, false});
            states.push_back((state){nums[i] / 2, i, true});
        }

        // sort(states.begin(), states.end(),
        // [](state& lhs, state& rhs) {
        //     if(lhs.val == rhs.val)
        //         return lhs.idx > rhs.idx;
        //     return lhs.val > rhs.val;
        // });

        for(auto &elem : states) {
            int idx = elem.idx;
            int val = elem.val;
            if(elem.shouldInsert) {
                tree.update(idx, val);
            }
            else {
                ans += tree.query(0, idx);
            }
        }

        // ordered_set set;

        // for(int i = nums.size() - 1; i >= 0; --i) {
        //     ans += set.order_of_key(ceil(nums[i] / 2.0));
        //     set.insert(nums[i]);
        // }

        // or:

        // for(int i = nums.size() - 1; i >= 0; --i) {
        //     ans += set.order_of_key(nums[i]);
        //     set.insert(nums[i] * 2);
        // }

        // for(int i = 0; i < sz; ++i) {
        //     ans += query(0, min(idx, val));
        //     update(idx, 1);
        // }

        return ans; 
    }
};
