// accepted
// https://codeforces.com/contest/1694/problem/A
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
        int num0s, num1s;
        cin >> num0s >> num1s;
        string res;

        while(num0s || num1s) {
            if(num1s) {
                res += '1';
                num1s--;
            }
            if(num0s) {
                res += '0';
                num0s--;
            }
        }

        cout << res << "\n";
    }	
    
    return 0; 
}
