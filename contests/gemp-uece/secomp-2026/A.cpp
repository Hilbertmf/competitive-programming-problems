// https://codeforces.com/group/FOtuBenVgP/contest/692619
// https://codeforces.com/group/FOtuBenVgP/contest/692619/problem/A
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
    string s;
    int n;
    cin >> s >> n;
    for(int i = 0; i < n; ++i) {
        string cur_str;
        cin >> cur_str;

        bool is_healthy = cur_str.size() % s.size() == 0;

        if (is_healthy) {
            for(int j = 0, idx = 0; j < cur_str.size(); ++j) {
                if (s[idx] != cur_str[j]) {
                    is_healthy = false;
                    break;
                }

                ++idx;
                if (idx >= s.size()) idx = 0;
            }

        }

        if(is_healthy) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
        
    }



    return 0;
}
