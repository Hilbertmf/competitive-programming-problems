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
 
int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        unordered_set<int> elems(arr.begin(), arr.end());
        
        bool found = false;
        int ans = 1;
        for(int i = 0; i < n && !found; ++i) {
            int _xor = -1;
            
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                if(_xor == -1)
                    _xor = arr[j];
                else 
                    _xor ^= arr[j];
            }
            
            if(elems.find(_xor) != elems.end()) {
                ans = _xor;
                found = true;
            }
        }

        cout << ans << "\n";
    }	
    
    return 0; 
}
