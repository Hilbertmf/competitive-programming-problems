// https://codeforces.com/contest/1883/problem/B
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

int32_t main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool possible = false;

        int p_size = n - k;
        map<char, int> char_map;

        for(auto &c : s) {
            char_map[c]++;
        }

        int pairs = p_size / 2;
        int current_pairs = 0;

        for(auto &[c, occ] : char_map) {					
            if(current_pairs == pairs)
                break;
            if(occ > 1) {

                if(occ / 2 >= pairs - current_pairs) {
                    current_pairs = pairs;
                    break;
                }
                else
                    current_pairs += occ / 2;
            }
        }


        if(pairs == current_pairs) {
            if(p_size % 2 == 0 || s.size() - current_pairs * 2 > 0)
                possible = true;
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
