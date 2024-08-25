// https://codeforces.com/contest/2003/problem/B
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
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &num : a) cin >> num;

        multiset<int> s(a.begin(), a.end());

        int turn = 1;
        while (s.size() > 1) {
            if (turn)
                s.erase(s.begin());
            else
                s.erase(s.find(*s.rbegin()));
            turn ^= 1;
        }
        
        cout << *s.begin() << "\n";

    }
    
    return 0;
}
