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

        int len, jump_dist, swim_dist;
        cin >> len >> jump_dist >> swim_dist;

        vector<char> river(len);
        for(int i = 0; i < len; ++i) {
            cin >> river[i];
        }
        bool possible = true;

        int start = -1;
        
        for(int i = jump_dist - 1; i >= 0; --i) {
            if (river[i] == 'L') {
                start = i;
                break;
            }
            else if (river[i] == 'W')
                start = max(start, i);
        }

        if (start == -1)
            possible = false;

        if (jump_dist > len) 
            possible = true;

        for(int i = start; i < len && possible && jump_dist <= len;) {
            
            if (river[i] == 'L' && i + jump_dist >= len) {
                possible = true;
                break;
            }
            
            if (river[i] == 'L') {
                int pos = i;
                for(int j = jump_dist + i; j > i; --j) {
                    if (river[j] == 'L') {
                        pos = j;
                        break;
                    }
                    else if (river[j] == 'W') {
                        pos = max(pos, j);
                    }
                }
                if (pos == i) pos++;
                i = pos;
                if (river[i] == 'C')
                    possible = false;
            }
            else if (river[i] == 'W') {
                swim_dist--;
                if (swim_dist < 0) {
                    possible = false;
                }
                i++;
            }
            else if (river[i] == 'C') {
                possible = false;
            }
        }

        
        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
