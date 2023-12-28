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
        string s;
        cin >> s;
        set<char> cons {'b', 'c', 'd'};

        vector<string> split;

        int curr_cons = 0;
        int curr_vow = 0;
        string tmp;
        for(int i = 0; i < n; ++i) {
            if(i < n - 1 && cons.find(s[i]) != cons.end() && tmp.size() >= 2) {
                if(cons.find(s[i + 1]) != cons.end() && i != n - 2) {
                    tmp += s[i];
                }
                else {
                    split.push_back(tmp);
                    tmp.clear();
                    tmp += s[i];
                }
            }
            else {

                tmp += s[i];
            }

        }        

        if(!tmp.empty()) split.push_back(tmp);

        for(int i = 0; i < split.size(); ++i) {
            cout << split[i];
            if(i != split.size() - 1)
                cout << ".";
        }
        cout << "\n";
    }
    
    return 0;
}
