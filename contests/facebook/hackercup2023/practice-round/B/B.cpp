// https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/B
// accepted
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
const int MOD = 1000000007; // 10^9 - 7 
 
int32_t main() { 
	FASTIO;
    int t;
    cin >> t;
    int num_case = 1;
    while (t--) {
		int r, c, a, b;
		cin >> r >> c >> a >> b;

        cout << "Case #" << num_case << ": ";
		if(r > c) {
			cout << "YES" << "\n";	
		}
		else {
			cout << "NO" << "\n";				
		}
        num_case++;
    }
	
	return 0; 
}
