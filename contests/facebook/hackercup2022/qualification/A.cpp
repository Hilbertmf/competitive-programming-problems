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
    int tests;
    cin >> tests;
    for(int t = 1; t <= tests; ++t) {
        
        int numParts, capacity;
        cin >> numParts >> capacity;
        vector<int> parts(numParts);
        map<int, int> styleMap;
        string ans = "YES";
        for(int i = 0; i < numParts; ++i) {
            cin >> parts[i];
            styleMap[parts[i]]++;
            if(styleMap[parts[i]] > 2) ans = "NO";
        }

        if(numParts > 2 * capacity) {
            ans = "NO";
        }
        
        

        cout << "Case #" << t << ": " << ans << "\n";
    }	
    
    return 0; 
}
