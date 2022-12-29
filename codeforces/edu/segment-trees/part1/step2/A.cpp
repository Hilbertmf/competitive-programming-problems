#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)INT_MAX
#define NINF (int)INT_MIN
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

struct data {
    long long total;
    long long prefix;
    long long suffix;
    long long best;
};

struct segtree {
    int size;
    vector<data> sums;

    void init(int sz) {
        size = sz;
        sums = vector<data>(size * 4);
    }

    void update(int pos, int val) {
        update(pos, val, 0, size - 1, 0);
    }

    void update(int pos, int val, int l, int r, int node) {
        if(l == r) {
            sums[node] = (data){val, val, val, val};
        }
        else {
            int mid = (l + r) / 2;
            if(pos <= mid)
                update(pos, val, l, mid, 2*node + 1);
            else
                update(pos, val, mid+1, r, 2*node + 2);

            data nodeData;
            data left = sums[2*node + 1], right = sums[2*node + 2];
            nodeData.total = left.total + right.total;
            nodeData.prefix = max({left.prefix, left.total, (left.total + right.prefix),
                                    left.total + right.total});
            nodeData.suffix = max({right.suffix, right.total, right.total + left.suffix,
                                    right.total + left.total});
            nodeData.best = max({nodeData.prefix, nodeData.suffix, nodeData.total});
            sums[node] = nodeData;
        }
    }

    data query(int ql, int qr) {
        return query(ql, qr, 0, size - 1, 0);
    }

    data query(int ql, int qr, int l, int r, int node) {
        if(ql <= l && qr <= r)
            return sums[node];
        if(l > qr || r < ql)
            return (data){0, 0, 0, 0};
        data result;
        
        int mid = (l + r) / 2;
        data left = query(ql, qr, l, mid, node);
        data right = query(ql, qr, mid+1, r, node);

        result.total = left.total + right.total;
        if(left.total == 0 && right.total == 0)
            result.total = 0;
        else if(left.total == 0) 
            result.total = right.total;
        else if(right.total == 0)
            result.total = left.total;
        else
            result.total = left.total + right.total;

        result.prefix = max({left.prefix, left.total, (left.total + right.prefix),
                                    left.total + right.total});
        result.suffix = max({right.suffix, right.total, right.total + left.suffix,
                                    right.total + left.total});
        result.best = max({left.best, right.best, left.suffix + right.prefix, left.suffix + right.total,
                    left.total + right.prefix, left.total + right.total});
        
        return result;
    }

};

int main() {
    int n, m;
    cin >> n >> m;
    int num = 0;
    segtree tree;
    tree.init(n);

    for(int i = 0; i < n; ++i) {
        cin >> num;
        tree.update(i, num);
    }

    cout << tree.query(0, n - 1).best << "\n";

    while(m--) {
        int pos, val;
        cin >> pos >> val;

        tree.update(pos, val);
        cout << tree.query(0, n - 1).best << "\n";
    }

    return 0;
}