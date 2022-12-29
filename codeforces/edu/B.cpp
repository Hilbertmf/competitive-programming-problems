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

struct segtree {
    int size;
    vector<int> mins;
    void init(int sz) {
        size = sz;
        mins = vector<int>(size * 4, INF);
    }

    int queryMin(int ql, int qr, int l, int r, int node) {
        if(ql <= l && qr >= r) return mins[node];
    
        int mid = (l + r) / 2;
        return queryMin(ql, qr, )
    }
    
    int queryMin(int ql, int qr) {
        return queryMin(ql, qr, 0, size - 1, 0);
    }

};

int main() { 
	FASTIO;
	
	
	return 0; 
}
