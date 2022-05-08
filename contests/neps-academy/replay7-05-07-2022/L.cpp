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
	int n, m;
    std::cin >> n >> m;
    vector<pair<int, int>> op(m);
    for(int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        pair<int, int> p = make_pair(a,b);
    }

    for(int i = 0; i < m; ++i) {
        pair<int, int> p = op[i];
        
    }
	
	return 0; 
}
