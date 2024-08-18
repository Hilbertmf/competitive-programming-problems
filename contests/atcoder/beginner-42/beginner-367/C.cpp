#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

void backtrack(int i, int n, int k, vector<int>& r,
vector<vector<int>>& seqs, vector<int>& cur, int sum) {
    
    if (i == n) {
        if (sum % k == 0 && cur.size() == n)
            seqs.push_back(cur);
        return;
    }

    for(int pos = i; pos < n; ++pos) {
        
        for(int j = 1; j <= r[i]; ++j) {
            cur.push_back(j);
            backtrack(pos + 1, n, k, r, seqs, cur, sum + j);
            cur.pop_back();
        }
    }
    
}

int32_t main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    for(int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    vector<vector<int>> seqs;
    vector<int> cur;
    backtrack(0, n, k, r, seqs, cur, 0);
    
    for(auto &seq : seqs) {
        for(int i = 0; i < seq.size(); ++i) {
            if (i > 0) cout << " ";
            cout << seq[i];
        }
        cout << "\n";
    }

    return 0;
}
