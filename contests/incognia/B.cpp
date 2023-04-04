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
// #define int long long

int main() { 
	FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int count2 = 0, count3 = 0;
        while(n % 2 == 0) {
            count2++;
            n /= 2;
        }

        while(n % 3 == 0) {
            count3++;
            n /= 3;
        }
        
        if(count2 <= count3 && n == 1) {
            cout << count2 + count3 << "\n";
        }
        else
            cout << -1 << "\n";

    }
	
	return 0; 
}
