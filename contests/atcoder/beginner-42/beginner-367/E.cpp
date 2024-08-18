#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

void print(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << "\n";
}

int32_t main() {
    FASTIO;

    int n;
    long long k;
    cin >> n >> k;
    
    vector<int> X(n);
    vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> X[i];
        X[i]--;  // Convert to 0-based index
    }    
    for (int i = 0; i < n; i++) cin >> A[i];
    vector<int> B = A;

    if (k == 0) {
        print(B);
    }
    else {

        int max_p = log2(k) + 1;
        vector<vector<int>> up(n, vector<int>(max_p));

        // precompute binary lifting matrix        
        for (int i = 0; i < n; i++)
            up[i][0] = X[i];

        for (int p = 1; p < max_p; p++) {
            for (int i = 0; i < n; i++) {
                up[i][p] = up[ up[i][p - 1] ][p - 1];
            }
        }

        // go up k times        
        for (int i = 0; i < n; i++) {
            int cur = i;
            long long jumps = k;
            
            for(int p = 0; p < max_p; ++p) {
                if (jumps & 1)
                    cur = up[cur][p];
                jumps >>= 1;
            }
            B[i] = A[cur];
        }

        print(B);
    }

    return 0;
}
