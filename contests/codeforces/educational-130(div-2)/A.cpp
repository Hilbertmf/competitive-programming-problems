// accepted
// https://codeforces.com/contest/1697/problem/A
// time: O(n)
// space: O(1)
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
        int numBenches, energy;
        cin >> numBenches >> energy;
        vector<int> benches(numBenches);
        int sum = 0;
        for(int i = 0; i < numBenches; ++i) {
            cin >> benches[i];
            sum += benches[i];
        }

        if(energy >= sum)
            cout << 0 << "\n";
        else
            cout << sum - energy << "\n";
    }	
    
    return 0; 
}
