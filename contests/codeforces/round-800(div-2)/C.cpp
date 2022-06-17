// accepted
// https://codeforces.com/contest/1694/problem/C
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

/*
- first >= 0
- last <= 0
- total sum = 0
- if idx < last non-zero and prefix[idx] == 0 : No
*/

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> elems(n);
        vector<long long> prefix(n);
        bool possible = true;
        for(int i = 0; i < n; ++i) {
            cin >> elems[i];
            prefix[i] += elems[i];

            if(i > 0)
                prefix[i] += prefix[i - 1];
        }

        if(elems[0] < 0 || elems[n - 1] > 0 || prefix[n - 1] != 0)
            possible = false;
        
        int lastNonZeroIdx = -1;
        for(int i = n - 1; i >= 0 && lastNonZeroIdx == -1 && possible; --i) {
            if(elems[i] != 0)
                lastNonZeroIdx = i;
        }

        for(int i = 0; i < n && possible; ++i) {
            if(prefix[i] < 0 || (i < lastNonZeroIdx && prefix[i] == 0))
                possible = false;
        }

        if(possible) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}