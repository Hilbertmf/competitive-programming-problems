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

struct segtree {
    int size;
    vector<vector<int>> sums;

    void init(int sz) {
        size = sz;
        sums = vector<vector<int>>(size * 4, vector<int>(26));
    }

    vector<int> query(int ql, int qr) {
        return query(ql, qr, 0, size - 1, 0);
    }
    vector<int> query(int ql, int qr, int l, int r, int node) {
        if(ql <= l && qr >= r)
            return sums[node];
        if(l > qr || r < ql)
            return vector<int>(26);
        int mid = (l + r) / 2;
        vector<int> res(26);
        auto left = query(ql, qr, l, mid, 2*node + 1);
        auto right = query(ql, qr, mid + 1, r, 2*node + 2);
        for(int i = 0; i < 26; ++i) {
            res[i] = left[i] + right[i];
        }
        return res;
    }

    void update(int pos, char val) {
        update(pos, val, 0, size - 1, 0);
    }
    void update(int pos, char val, int l, int r, int node) {
        if(l == r) {
            sums[node][val - 'A']++;
        }
        else {
            int mid = (l + r) / 2;
            if(pos <= mid) {
                update(pos, val, l, mid, 2*node + 1);
            }
            else {
                update(pos, val, mid + 1, r, 2*node + 2);
            }
            for(int i = 0; i < 26; ++i) {
                sums[node][i] = sums[2*node + 1][i] + sums[2*node + 2][i];
            }
        }
    }

};

bool isPalindrome(vector<int> charMap) {
    int numOdd = count_if(charMap.begin(), charMap.end(),
    [](int n) {
        return n & 1;
    });
    return numOdd <= 1;
}

int main() { 
    FASTIO;
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; ++t) {
        int n, q;
        cin >> n >> q;
        string blocks;
        cin >> blocks;
        segtree tree;
        tree.init(blocks.size());
        for(int i = 0; i < blocks.size(); ++i) {
            tree.update(i, blocks[i]);
        }
        
        int ans = 0;

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            if(isPalindrome(tree.query(l, r)))
                ans++;
        }

        cout << "Case #" << t+1 << ": " << ans << "\n";
    }

    return 0; 
}
