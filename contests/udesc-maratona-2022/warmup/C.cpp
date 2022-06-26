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
    int q;
    cin >> q;

    vector<int> squares{0};
    int n = 1;
    int sq = 1;

    while(sq <= 100000000 + 1) {
        sq = pow(n, 2);
        ++n;
        squares.push_back(sq);
    }


    while (q--) {
        int l, r;
        cin >> l >> r;
        auto low = lower_bound(squares.begin(), squares.end(), l);
        auto high = lower_bound(squares.begin(), squares.end(), r);
        int ans = high - low + 1;
        if(*high != r) ans--;        

        cout << ans << "\n";
    }	
    
    return 0; 
}
