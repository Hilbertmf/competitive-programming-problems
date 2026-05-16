#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;

    if (n == 1) {
        ans = a[0];
    }
    else if (n == 2) ans = max(a[0], a[1]);
    else {
        
        unordered_multiset<int> m;
        if(a[0] > a.back()) {
            m = unordered_multiset<int>(a.begin(), a.end());
        }
        else {
            m = unordered_multiset<int>(a.rbegin(), a.rend());
        }

        if(*m.begin() >= *next(m.begin())) {
            ans += *m.begin();
            m.erase(m.begin());
            m.erase(m.begin());
        }
        else {
            ans += *next(m.begin());
            m.erase(m.begin());
            m.erase(m.begin());
            m.erase(m.begin());
        }
        
        while (!m.empty()) {
            if (m.size() == 1) {
                ans += *m.begin();
                m.clear();
            }
            else {
                if(*m.begin() < *next(m.begin())) {
                    ans += *m.begin();
                }
                else {
                    ans += *next(m.begin());
                } 
                m.erase(m.begin());
                m.erase(m.begin());
            }
            
        }
    }

    cout << ans << "\n";


    return 0;
}
