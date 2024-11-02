/*
obs: we can use the observation that the final order of
elements will ALWAYS be:
pn pn-1 ... p2 p1
and then solve it
*/
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define INF 1e9
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool leaf(int from, int to) {
    return from == to;
}
bool allIn(int from, int to, int l, int r) {
    return l <= from && to <= r;
}
bool allOut(int from, int to, int l, int r) {
    return to < l || r < from;
}

class Segtree {
public:
    void init(int n) {
        size = n;
        nodes.resize(n * 4, 0);
        lazy.resize(n * 4, 0);
    }
    
    void build(vector<int>& vals) {
        build(vals, 0, 0, size - 1);
    }
    
    int query(int left, int right) {
        return query(left, right, 0, 0, size - 1);
    }
    
    void updateRange(int left, int right, int val) {
        updateRange(left, right, val, 0, 0, size - 1);
    }
    
    void update(int pos, int val) {
        update(pos, val, 0, 0, size - 1);
    }

    void copyToArr(vector<int>& arr) {
        arr.resize(size);
        copyToArr(arr, 0, 0, size - 1);
    }
private:
    int size;
    vector<int> nodes;
    vector<int> lazy;
    
    void build(vector<int>& vals, int node, int from, int to) {
        if (leaf(from, to)) {
            nodes[node] = vals[from];
        } else {
            int mid = MID(from, to);
            build(vals, 2 * node + 1, from, mid);
            build(vals, 2 * node + 2, mid + 1, to);
            nodes[node] = nodes[2 * node + 1] + nodes[2 * node + 2];
        }
    }
    
    void propagate(int node, int from, int to) {
        if (lazy[node] != 0) {
            nodes[node] += lazy[node] * (to - from + 1);
            if (!leaf(from, to)) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0; 
        }
    }
    
    int query(int l, int r, int node, int from, int to) {
        propagate(node, from, to);
        if (allIn(from, to, l, r)) {
            return nodes[node];
        }
        if (allOut(from, to, l, r)) {
            return 0;
        }
        int mid = MID(from, to);
        return query(l, r, 2 * node + 1, from, mid) +
               query(l, r, 2 * node + 2, mid + 1, to);
    }
    
    void updateRange(int l, int r, int val, int node, int from, int to) {
        propagate(node, from, to);
        if (allIn(from, to, l, r)) {
            lazy[node] += val;
            propagate(node, from, to);
        } else if (!allOut(from, to, l, r)) {
            int mid = MID(from, to);
            updateRange(l, r, val, 2 * node + 1, from, mid);
            updateRange(l, r, val, 2 * node + 2, mid + 1, to);
            nodes[node] = nodes[2 * node + 1] + nodes[2 * node + 2];
        }
    }
    
    void update(int pos, int val, int node, int from, int to) {
        propagate(node, from, to);
        if (leaf(from, to)) {
            nodes[node] = val;
        } else {
            int mid = MID(from, to);
            if (pos <= mid) {
                update(pos, val, 2 * node + 1, from, mid);
            } else {
                update(pos, val, 2 * node + 2, mid + 1, to);
            }
            nodes[node] = nodes[2 * node + 1] + nodes[2 * node + 2];
        }
    }

    void copyToArr(vector<int>& arr, int node, int from, int to) {
        propagate(node, from, to);
        if (leaf(from, to)) {
            arr[from] = nodes[node];
        }
        else {
            int mid = MID(from, to);
            copyToArr(arr, 2 * node + 1, from, mid);
            copyToArr(arr, 2 * node + 2, mid + 1, to);
        }
    }
};

int main() {
    FASTIO;
    int t, tcase = 1;
    cin >> t;
    
    while(t--){

        int n, g, r, l;
        cin >> n >> g;
        vector<int> e(n + 1);
        for(int i = 1; i <= n; ++i) cin >> e[i];
        int MAX_ELEMENT = *max_element(e.begin(), e.end());
        
        Segtree seg;
        set<int> st;
        map<int, int> indices;
        seg.init(MAX_ELEMENT + 1);
        
        // if theres a tie, only consider lowest indices
        int MAX = -INF;
        int MIN = INF;
        for(int i = 1; i <= n; ++i) {
            if (indices.find(e[i]) == indices.end())
                indices[e[i]] = i;
            st.insert(e[i]);
            MAX = max(MAX, e[i]);
            if (e[i] < MIN) {
                MIN = e[i];
                seg.updateRange(0, e[i], 1);
            }
            else {
                seg.updateRange(0, MIN, 1);
                seg.updateRange(MIN + 1, e[i], 1);
            }
        }

        vector<int> arr;
        seg.copyToArr(arr);

        pair<int, int> ans;
        if (st.count(g)) {
            ans = {arr[g], 0};
        }
        else {
            set<int> nums(e.begin() + 1, e.end());
            auto it = nums.upper_bound(g);
            
            if (it != nums.begin()) l = *prev(it);
            if (it != nums.end()) r = *it;

            if (it == nums.end()) {
                ans = {arr[l], g - l};
            }
            else if (it == nums.begin()) {
                ans = {arr[r], r - g};
            }
            else {
                int dist_l = g - l, dist_r = r - g;
                if (dist_l == dist_r) {
                    ans = {min(arr[l], arr[r]), dist_l};
                }
                else if (dist_l < dist_r) {
                    ans = {arr[l], dist_l};
                }
                else {
                    ans = {arr[r], dist_r};
                }
            }
        }

        cout << "Case #" << tcase << ": ";
        cout << ans.first << " " << ans.second << "\n";
        tcase++;
    }
    
    return 0;
}

class TrieNode{
public:
    char val;
    int freq;
    unordered_map<char, TrieNode*> children;
    TrieNode(char c) {
        val = c;
        freq = 0;
    }
};

class Solution {
public:
    void dfsCreate(TrieNode* cur, string& word, int idx) {
        cur->freq++;
        if (idx + 1 <= word.size() - 1) {
            if (!cur->children.count(word[idx + 1]))
                cur->children[word[idx + 1]] = new TrieNode(word[idx + 1]);
            dfsCreate(cur->children[word[idx + 1]], word, idx + 1);
        }
    }
    int dfs(TrieNode* cur, string& word, int idx) {
        int res = cur->freq;
        if (idx + 1 <= word.size() - 1)
            res += dfs(cur->children[word[idx + 1]], word, idx + 1);

        return res;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> scores;

        TrieNode* root = new TrieNode('_');

        for(auto &word : words) {
            if (!root->children.count(word[0])) {
                root->children[word[0]] = new TrieNode(word[0]);
            }
            dfsCreate(root->children[word[0]], word, 0);
        }

        root->freq = 0;
        for(auto &word : words) {
            int score = dfs(root->children[word[0]], word, 0);
            scores.push_back(score);
        }
        return scores;
    }
};



class MyCalendar {
public:
    set<pair<int, int>> intervals;
    MyCalendar() {
        intervals = set<pair<int, int>>();
    }
    
    bool dont_intersect(pair<int, int> p) {
        if (p.first >= intervals.rbegin()->second ||
            p.second <= intervals.begin()->first)
            return true;

        auto right = intervals.upper_bound(p);
        auto left = prev(right);
        return left->second <= p.first && p.second <= right->first;
    }
    
    bool book(int start, int end) {
        if (intervals.empty() || dont_intersect({start, end})) {
            intervals.insert({start, end});
            return true;
        }
        else {
            return false;
        }
    }
};