#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

class SegmentTree {
private:
    vector<int> tree;  // Segment tree array
    vector<int> lazy;  // Lazy propagation array
    int n;  // Size of the original input array

    // Build the tree with initial values
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            // Leaf node, corresponds to a single element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // Range update with lazy propagation
    void rangeAdd(int node, int start, int end, int l, int r, int value) {
        // Update the current node if there's a pending update
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // Out of range
        if (start > end || start > r || end < l) {
            return;
        }

        // Current segment is fully within the range
        if (start >= l && end <= r) {
            tree[node] += value;
            if (start != end) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }

        // Partially in range
        int mid = (start + end) / 2;
        rangeAdd(2 * node + 1, start, mid, l, r, value);
        rangeAdd(2 * node + 2, mid + 1, end, l, r, value);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Range maximum query with lazy propagation
    int rangeMax(int node, int start, int end, int l, int r) {
        // Update the current node if there's a pending update
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // Out of range
        if (start > end || start > r || end < l) {
            return LLONG_MIN; // Minimum possible value, as we are looking for max
        }

        // Fully in range
        if (start >= l && end <= r) {
            return tree[node];
        }

        // Partially in range
        int mid = (start + end) / 2;
        int leftMax = rangeMax(2 * node + 1, start, mid, l, r);
        int rightMax = rangeMax(2 * node + 2, mid + 1, end, l, r);
        return max(leftMax, rightMax);
    }

public:
    // Constructor to build the tree with the initial array
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    // Public method to perform range addition
    void addRange(int l, int r, int value) {
        rangeAdd(0, 0, n - 1, l, r, value);
    }

    // Public method to get range maximum
    int getRangeMax(int l, int r) {
        return rangeMax(0, 0, n - 1, l, r);
    }
};

vector<string> split(string& s) {
    stringstream ss(s);
    string buf;
    vector<string> res;
    while (getline(ss, buf, ' ')) {
        if (!buf.empty())
            res.push_back(buf);
    }
    return res;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--) {
        int l, r, n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];  
        }

        sort(arr.begin(), arr.end());
        int MAXN = arr.back();
        cin.ignore();

        SegmentTree tree(arr);
        vector<int> ans;
        while (m--) {
            string s;
            getline(cin, s);

            bool sum = s[0] == '+';

            s = s.substr(2);
            vector<string> nums = split(s);
            int l, r;
            l = stoi(nums[0]), r = stoi(nums[1]);

            if (l <= MAXN && MAXN <= r) {
                if(sum) {
                    MAXN++;
                }
                else {
                    MAXN--;
                }
            }

            ans.push_back(MAXN);

        }

        for(int i = 0; i < ans.size(); ++i) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    
    return 0;
}
