// accepted
// https://codeforces.com/contest/1700/problem/A
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (long long)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const long long MOD = 1000000007; // 10^9 - 7 

int main() { 
    FASTIO;
    long long t;
    cin >> t;
    while (t--) {
        long long rows, cols;
        cin >> rows >> cols;

        long long cost = 0;

        for(int i = 1; i < cols; ++i) {
            cost += i;
        }

        for(int i = cols; i <= rows * cols; i += cols) {
            cost += i;
        }

        cout << cost << "\n";        
                
    }	
    
    return 0; 
}
