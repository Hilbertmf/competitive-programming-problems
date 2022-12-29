#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

struct segtree{
    int size;
    vector<int> sums;

    void init(int sz) {
        size = sz;
        sums = vector<int>(sz * 4);
    }

    int query(int ql, int qr) {
        return query(ql, qr, 0, size - 1, 0);
    }
    
    int query(int ql, int qr, int l, int r, int node) {
        // totally included
        if(ql <= l && qr >= r)
            return sums[node];
        // totally excluded
        if(r < ql || l > qr)
            return 0;
        int mid = (l + r) / 2;
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
            // update
            int mid = (l + r) / 2;
            if(pos <= mid) {
                update(pos, val, l, mid, 2*node + 1);
            }
            else {
                update(pos, val, mid + 1, r, 2*node + 2);
            }
            // propagate
            sums[node] = sums[2*node + 1] + sums[2*node + 2];
        }
    }

};

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n+1);
        long long ans = 0;
        vector<pair<int, int>> numsAndIndices;
        segtree tree;
        tree.init(n+1);
        for(int i = 1; i <= n; ++i) {
            cin >> arr[i];
            if(arr[i] < i) numsAndIndices.push_back({arr[i], i});
        }

        sort(numsAndIndices.begin(), numsAndIndices.end());

        for(auto &[val, idx] : numsAndIndices) {
            // min between idx and val - 1 because i < arr[j]
            ans += tree.query(0, min(idx, val - 1));
            tree.update(idx, 1);            
        }

        cout << ans << "\n";
    }	
    
    return 0; 
}
