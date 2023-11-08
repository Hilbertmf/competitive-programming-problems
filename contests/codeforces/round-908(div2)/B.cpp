// https://codeforces.com/contest/1894/problem/B
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
        int n;
        cin >> n;
        vector<int> a(n);
        bool possible = true;
        multiset<int> st;
        set<int> repeated_elems;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(st.find(a[i]) != st.end()) {
                repeated_elems.insert(a[i]);
            }
            st.insert(a[i]);
        }

        possible = repeated_elems.size() > 1;

        if(possible) {
            vector<int> b(n, 1);
            auto it = repeated_elems.begin();
            int r1 = *it;
            next(it);
            while (it != repeated_elems.end() && *it == r1) {
                ++it;
            }
            int r2 = *it;
            pair<int, int> p1;
            pair<int, int> p2;

            for(int i = 0, count = 0; i < n && count < 2; ++i) {
                if(a[i] == r1) {
                    if(count == 0) p1.first = i;
                    else p1.second = i;
                    count++;
                }
            }

            for(int i = 0, count = 0; i < n && count < 2; ++i) {
                if(a[i] == r2) {
                    if(count == 0) p2.first = i;
                    else p2.second = i;
                    count++;
                }
            }
            b[p1.second] = 2;
            b[p2.second] = 3;

            for(int i = 0; i < n; ++i) {
                cout << b[i];
                if(i < n - 1)
                    cout << " ";
            }
            cout << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }	
    
    return 0; 
}
