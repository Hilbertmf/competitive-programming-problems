// O(n+m)
// https://codeforces.com/contest/1894/problem/D
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
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        vector<int> c;
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < m; ++i) cin >> b[i];

        int ptr1 = 0, ptr2 = 0;
        sort(b.begin(), b.end(), greater<int>());

        while (ptr1 < n || ptr2 < m) {
            if(ptr1 >= n) {
                c.push_back(b[ptr2]);
                ptr2++;
            }
            else if(ptr2 < m && b[ptr2] >= a[ptr1]) {
                c.push_back(b[ptr2]);
                ptr2++;
            }
            else {
                c.push_back(a[ptr1]);
                ptr1++;
            }
        }

        for(int i = 0; i < c.size(); ++i) {
            cout << c[i];
            if(i < c.size() - 1) cout << " ";
        }
        cout << "\n";
    }	

    return 0; 
}
