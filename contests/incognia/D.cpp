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
        string s, s1;
        cin >> s >> s1;
        reverse(s1.begin(), s1.end());
        if(s == s1) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }

	
	return 0; 
}
