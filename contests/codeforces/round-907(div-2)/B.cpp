// https://codeforces.com/contest/1891/problem/B
// accepted
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
#define int long long
 
int32_t main() { 
    FASTIO;
    int t;
    cin >> t;

    vector<int> powers_2(31);
    powers_2[0] = 1;
    for(int i = 1; i <= 30; ++i) {
        powers_2[i] = 2 * powers_2[i - 1];
    }
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<int> x(q);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < q; ++i) {
            cin >> x[i];
        }

        set<int> x_set;
        vector<int> x_unique;

        for(int i = 0; i < q; ++i) {
            if(x_set.find(x[i]) == x_set.end()) {
                x_unique.push_back(x[i]);
                x_set.insert(x[i]);
            }
        }


        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < x_unique.size() && j < 30; ++j) {
                if(a[i] >= powers_2[x_unique[j]] && a[i] % powers_2[x_unique[j]] == 0) {
                    a[i] += powers_2[x_unique[j] - 1];
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            cout << a[i];
            if(i != n - 1)
                cout << " ";
        }
        cout << "\n";
    }
    
    return 0; 
}
