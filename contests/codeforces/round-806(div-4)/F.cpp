#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; 
using namespace __gnu_pbds;
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

typedef tree<
long long, // key type
null_type, // mapped-policy
less_equal<long long>, // key comparison function
rb_tree_tag, // underlying data structure
tree_order_statistics_node_update>
ordered_multiset;
// using less_equal exchanges upper and lower bounds
// use upper bound to erase elements
// also order_of_key refers to the first occurence of key

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n+1);
        vector<long long> numsGreaterThanIdx(n+1);
        ordered_multiset tree;
        long long ans = 0;

        for(int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }

        if(arr[n] < n) {
            tree.insert(arr[n]);
        }
        
        for(int i = n - 1; i >= 1; --i) {
            if(arr[i] < i) {
                
                long long tmp;
                tmp = tree.size() - tree.order_of_key(i+1);
                                
                if(tmp > 0)
                    ans += tmp;
                
                tree.insert(arr[i]);

            }
        }
        
        cout << ans << "\n";
    }	
    
    return 0; 
}
