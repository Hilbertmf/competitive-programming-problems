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
        vector<int> arr1(n);
        vector<int> arr2(n);
        bool possible = true;
        int maxDiff = -INF;

        for(int i = 0; i < n; ++i) {
            cin >> arr1[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> arr2[i];
            maxDiff = max(maxDiff, arr1[i] - arr2[i]);
        }

        for(int i = 0; i < n && possible; ++i) {
            if(arr1[i] < arr2[i]) {
                possible = false;
            }
            int currDiff = arr1[i] - arr2[i];
            if(arr2[i] != 0 && currDiff < maxDiff)
                possible = false;
        }

        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    
    return 0; 
}
