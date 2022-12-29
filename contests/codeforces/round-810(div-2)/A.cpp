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
        int n;
        cin >> n;
        vector<int> perm(n+1);
        for(int i = 1; i <= n; ++i) {
            perm[i] = i;
        }
        sort(perm.begin() + 1, perm.end(), greater<int>());
        for(int i = 2; i <= n; ++i) {
            if(perm[i] % i == 0)
                swap(perm[i], perm[i+1]);
        }
        int weight = 0;
        for(int i = 1; i <= n; ++i) {
            if(perm[i] % i == 0) weight++;
        }

        for(int i = 1; i <= n; ++i) {
            cout << perm[i];
            if(i != n) cout << " ";
        }
        cout << "\n";
    }	
    
    return 0; 
}
