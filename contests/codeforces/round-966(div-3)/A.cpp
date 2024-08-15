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

        string s;
        cin >> s;

        bool pos = true;
        string num;
        if (s.size() > 2)
            num = s.substr(2);
        if (s.size() <= 2 || s.substr(0, 2) != "10" ||
            (!num.empty() && stoi(num) < 2 || num[0] == '0')) {
                pos = false;
        }
        if(pos) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
    
    return 0;
}
