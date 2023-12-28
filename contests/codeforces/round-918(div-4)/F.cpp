#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

typedef tree<
long long, // key type
null_type, // mapped-policy
less_equal<long long>, // key comparison function
rb_tree_tag, // underlying data structure
tree_order_statistics_node_update>
ordered_multiset;

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end());
        ordered_multiset st;
        int count;

        for(int i = n - 1; i >= 0; --i) {
            int a_elem = v[i].first;
            int b_elem = v[i].second;
            st.insert(b_elem);
            count = st.order_of_key(b_elem);
            ans += count;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}