// https://codeforces.com/contest/1993/problem/A
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
        string ans;
        cin >> n >> ans;
        map<char, int> count;
        for(auto &c : ans) {
            count[c]++;
        }

        int best = 0;
        for(int c = 'A'; c <= 'D'; ++c) {
            best += min(count[c], n);
        }

        cout << best << "\n";
    }
    
    return 0;
}
