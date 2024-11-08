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

        int cur = 0;
        int player = 0;
        int turn = 1;
        while (abs(cur) <= n) {
            int move = 2 * turn - 1;
            if (player) cur += move;
            else cur -= move;

            player ^= 1;
            turn++;
        }

        if(player == 0) {
            cout << "Kosuke" << "\n";
        }
        else {
            cout << "Sakurako" << "\n";
        }
    }
    
    return 0;
}
