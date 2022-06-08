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
// accepted
// https://codeforces.com/contest/1690/problem/A
int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int numBlocks;
        cin >> numBlocks;
        int h1 = ceil(numBlocks / 3.0);
        int h2 = h1 - 1, h3 = h1 - 2;

        // DEBUG(numBlocks);
        while(h1 + h2 + h3 < numBlocks) {
            ++h1;
            h2 = h1 - 1;
            h3 = numBlocks - (h1 + h2);
            if(h3 <= 0) {
                h2--;
                h3++;
            }
        }

        cout << h2 << " " << h1 << " " << h3 << "\n";
    }
    
    
    return 0; 
}
