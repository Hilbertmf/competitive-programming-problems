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

        stack<pair<char, int>> up;
        stack<pair<char, int>> lw;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                if(s[i] != 'B')
                    up.push({s[i], i});
                else if(!up.empty()) {
                    up.pop();
                }
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                if(s[i] != 'b')
                    lw.push({s[i], i});
                else if(!lw.empty()) {
                    lw.pop();
                }
                
            }
        }

        string res;

        while (!up.empty() || !lw.empty()) {
            if(up.empty()) {
                res+= lw.top().first;
                lw.pop();
            }
            else if(lw.empty()) {
                res+= up.top().first;
                up.pop();
            }
            else {
                if(lw.top().second > up.top().second) {
                    res += lw.top().first;
                    lw.pop();
                }
                else {
                    res += up.top().first;
                    up.pop();
                }
            }
        }

        reverse(res.begin(), res.end());
        cout << res << "\n";

    }


    return 0;
}
