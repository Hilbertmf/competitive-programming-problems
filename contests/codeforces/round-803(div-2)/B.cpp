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
        int numPiles, sizeOp;
        cin >> numPiles >> sizeOp;
        vector<long long> piles(numPiles);
        for(int i = 0; i < numPiles; ++i) cin >> piles[i];
        
        int numTallPiles = 0;
        if(sizeOp == 1) {
            if(numPiles & 1) {
                cout << (numPiles - 1) / 2 << "\n";
            }
            else {
                cout << (numPiles - 2) / 2 << "\n";
            }
            continue;
        }

        for(int i = 1; i < numPiles - 1; ++i) {
            if(piles[i] > piles[i-1] + piles[i+1])
                numTallPiles++;
        }

        cout << numTallPiles << "\n";
    }	
    
    return 0; 
}
