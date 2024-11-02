#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define INF 1e9

int MAX_N = 3e5;
int TOTAL_N = 2e6;
int MAX_E = 1e6;

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

pair<int, int> solve(int n, int g, vector<int>& e) {
    pair<int, int> ans;
    int l, r;
    int MAX_ELEMENT = *max_element(e.begin(), e.end());        
    Segtree seg;
    set<int> st;
    seg.init(MAX_ELEMENT + 1);
    
    // if theres a tie, only consider lowest indices
    int MAX = -INF;
    int MIN = INF;
    for(int i = 1; i <= n; ++i) {
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
    
    return ans;
}

pair<int, int> solve_brute(int n, int g, vector<int>& e) {
    pair<int, int> ans;
    map<int, int> mp;

    // simulate process
    int MIN = INF;
    for(int i = 1; i <= n; ++i) {
        if (e[i] < MIN) {
            MIN = e[i];
            mp[e[i]] = i;
        }
        else {
            int nxt, prev = i;
            for(auto &[k, v] : mp) {
                if (k >= e[i]) break;
                nxt = v;
                v = prev;
                prev = nxt;
            }
            mp[e[i]] = prev;
        }
    }

    // find ans
    if(mp.find(g) != mp.end()) {
        ans = {mp[g], 0};
    }
    else {
        int dist = INF, idx = 1;
        ans = {idx, dist};
        for(auto &[k, v] : mp) {
            
            int cur_dist = abs(k - g);
            if (cur_dist < dist) {
                ans = {v, cur_dist};
                dist = cur_dist;
            }
            else if (cur_dist == dist)
                ans.first = min(ans.first, v);
        }
    }
    return ans;
}

int n, g;
vector<int> e;
void gen_input() {    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib_n(1, min(MAX_N, abs(TOTAL_N)));
    uniform_int_distribution<> distrib_e(1, MAX_E);
    // n = distrib_n(gen);
    n = min(MAX_N, abs(TOTAL_N));
    g = distrib_e(gen);
    TOTAL_N -= n;
    if (TOTAL_N <= 0) TOTAL_N = 10;
    if (n < 2) n = 2;
    e.resize(n + 1, 0);
    unordered_set<int> seen;
    seen.reserve(n);
    for(int i = 1; i <= n; ++i) {
        int cur = distrib_e(gen);
        while (seen.count(cur)) {
            cur = distrib_e(gen);
        }
        e[i] = cur;
        seen.insert(cur);
    }
}

int main() {
    FASTIO;
    int t = 85, tcase = 0;
    while (t--) {
        gen_input();
        pair<int, int> ans_opt = solve(n, g, e);
        // cout << "optimized finish" << endl;
        DEBUG(n);
        cout << "Case #" << tcase << ": ";
        cout << ans_opt.first << " " << ans_opt.second << "\n";
        tcase++;
        pair<int, int> ans_brute = solve_brute(n, g, e);
        cout << "brute finish" << endl;

        if(ans_brute == ans_opt) {
            DEBUG(n);
            cout << "OK!" << endl;
        }
        else {
            DEBUG(n);
            cout << "WRONG ANSWER" << endl;
            DEBUG(g);
            cout << "e: " << "\n";
            for(int i = 1; i <= n; ++i) {
                cout << e[i] << " ";
            }
            cout << endl;
        }

    }   
}