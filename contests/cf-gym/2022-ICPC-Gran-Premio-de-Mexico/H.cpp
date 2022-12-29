// acc
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
    int n;
    cin >> n;
    if(n % 4 == 0) {
        n /= 4;
        cout << n*n << "\n";
    }
    else {
        int l1 = n / 4;
        n -= 2*(l1);
        n /= 2;
        cout << l1 * n << "\n";
    }
    int l1 = n/4;

    
    return 0; 
}
