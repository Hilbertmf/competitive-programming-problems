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
    vector<int> powers(30);
    
    while(t--){

        int op, v;
        cin >> op >> v;

        if(op == 1) {
            powers[v]++;
        }
        else {
            int sum = 0;

            for(int i = 30 - 1; i >= 0; --i) {
                if(powers[i] == 0) continue;
                int p = 1 << i;

                if(v >= p) {
                    if(powers[i] >= (double)v / p)
                        v %= p;
                    else
                        v -= p * powers[i];
                }
                if(v == 0) break;
            }

            if(v == 0) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }

    }
    
    return 0;
}
