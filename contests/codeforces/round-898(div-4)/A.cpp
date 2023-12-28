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

        string in;
        cin >> in;
        map<char, int> mp;
        mp['a'] = 0;
        mp['b'] = 1;
        mp['c'] = 2;

        int aux = 0;
        for(int i = 0; i < in.size(); ++i) {
            if(mp[in[i]] != i)
                aux++;
        }

        
        if(aux == 0 || aux == 2) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }        

    }
    
    return 0;
}
