// https://codeforces.com/contest/1883/problem/A
// accepted
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
#define int long long

void move_to_digit(int digit, vector<int>& dist_map) {

    dist_map[digit] = 0;

    for(int i = digit + 1, j = 1; i < dist_map.size(); ++i, ++j) {
        dist_map[i]	= j;
    }

    for(int i = digit - 1, j = 1; i >= 0; --i, j++) {
        dist_map[i] = j;
    }

}

int32_t main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        vector<int> dist_map(10);
        for(int i = 0; i <= 9; ++i) {
            dist_map[i] = i;
        }

        string pin;
        cin >> pin;
        int ops = 0;

        for(auto &c : pin) {
            char tmp;
            if(c == '0')
                tmp = '9';
            else
                tmp = c - 1;
            
            int d = tmp - '0';
            if(dist_map[d] > 0) {
                ops += dist_map[d];
                move_to_digit(d, dist_map);
            }
            ops++;
        }

        cout << ops << "\n";
    }	
    
    return 0; 
}
