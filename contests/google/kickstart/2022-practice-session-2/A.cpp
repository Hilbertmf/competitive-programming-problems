// accepted
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b5503a
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
    for(int t = 0; t < tests; ++t) {
        int numBags, numKids;
        cin >> numBags >> numKids;

        int candies = 0, tmp;
        for(int i = 0; i < numBags; ++i) {
            cin >> tmp;
            candies += tmp;
        }
        
        int remainder = candies % numKids;

        cout << "Case #" << t+1 << ": " << remainder << "\n";
    }	
    return 0; 
}
