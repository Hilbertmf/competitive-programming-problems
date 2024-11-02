#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

void checkValidWindow(string& s, string& window, int step, bool& flag) {
    int diff = 0;
    for(int j = 0; j < s.size() && flag; j += step) {
        int left = j;
        int right = j + step;
        for(int k = left, l = 0; k < right; ++k, ++l) {
            if (s[k] != window[l])
                diff++;
            if (diff > 1) {
                flag = false;
                break;
            }
        }
    }
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        string s;
        cin >> n >> s;

        int ans = s.size();

        for(int i = 1; i <= s.size() / 2; ++i) {
            if (s.size() % i != 0) continue;

            string window1 = s.substr(0, i);
            string window2 = s.substr(i, i);
            bool ok1 = true;
            bool ok2 = true;

            checkValidWindow(s, window1, i, ok1);

            if (window1 != window2) {
                checkValidWindow(s, window2, i, ok2);
            }
            else {
                ok2 = ok1;
            }

            if (ok1 || ok2) {
                ans = i;
                break;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
