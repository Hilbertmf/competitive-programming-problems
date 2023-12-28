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


        for(int i = 0; i < 3; ++i) {
            string s;
            cin >> s;
            if(s.find('?') != string::npos) {

                map<char, int> mp;
                mp['A'] = 0;
                mp['B'] = 0;
                mp['C'] = 0;
                for(auto &c : s) {
                    mp[c]++;
                }

                if(mp['A'] == 0) {
                    cout << "A\n";
                }
                else if(mp['B'] == 0) {
                    cout << "B\n";
                }
                else if(mp['C'] == 0) {
                    cout << "C\n";
                }
            }
        }


    }
    
    return 0;
}
