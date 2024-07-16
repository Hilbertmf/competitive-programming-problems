// ac
// https://codeforces.com/contest/1988/problem/A
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, k;
        cin >> n >> k;  
        int op = 0;
        multiset<int> st;
        st.insert(n);

        
        while (st.size() < n) {
            int gt = *st.rbegin();
            st.erase(st.find(gt));

            for(int i = 0; i < k; ++i) {
                int num = gt / k;
                if (i == k - 1 && gt % k != 0)
                    num += gt % k;
                
                st.insert(num);
            }
            op++;
        }

        cout << op << "\n";
    }
    
    return 0;
}
