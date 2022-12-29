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
        vector<int> arr(n);
        int aux = 1;
        for(int i = 0; i < n; ++i, ++aux) {
            arr[i] = aux;
        }
        set<int> nums(arr.begin(), arr.end());

        vector<int> ans;
        ans.push_back(1);
        nums.erase(nums.find(1));
        int init = 2;
        aux = init;
        for(int i = 1; i < n; ) {
            while(aux <= n && i < n) {
                ans.push_back(aux);
                nums.erase(nums.find(aux));
                aux *= 2;
                ++i;
            }
            aux = *nums.lower_bound(init);
        }

        cout << 2 << "\n";
        for(int i = 0; i < n; ++i) {
            cout << ans[i];
            if(i != n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0; 
}
