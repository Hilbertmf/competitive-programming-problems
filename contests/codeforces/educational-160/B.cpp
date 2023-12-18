// https://codeforces.com/contest/1913/problem/B
// accepted
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

int main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        string s;
        cin >> s;

        map<int, int> count;
        for(auto &c : s) {
            count[c - '0']++;
        }

        int ans = -1;
        if(count[0] == count[1]) ans = 0;

        for(int i = 0; i < s.size() && ans == -1; ++i) {
            
            int digit = s[i] - '0';
            if(count[digit ^ 1] > 0) {
                count[digit ^ 1]--;
            }
            else {
                ans = min((int)s.size(), count[digit]);
            }
        }

        cout << ans << "\n";

    }
    
    return 0;
}
