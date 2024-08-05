// https://codeforces.com/contest/1993/problem/B
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

        int n, cur, sum;
        cin >> n;
        vector<int> a(n);
        map<int, int> count_parity;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            count_parity[a[i] % 2]++;
        }
        
        if(count_parity[0] == n || count_parity[1] == n) {
            cout << "0\n";
        }
        else {
            
            int max_odd = 0;
            multiset<int> evens;
            for(auto &num : a) {
                if (num & 1) max_odd = max(max_odd, num);
                else evens.insert(num);
            }

            int ans = 0;
            while (!evens.empty()) {
                if (*evens.begin() < max_odd) {
                    cur = *evens.begin();
                    evens.erase(evens.find(cur));
                }
                else {
                    cur = *evens.rbegin();
                }
                sum = cur + max_odd;
                max_odd = max(max_odd, sum);
                ans++;
            }

            cout << ans << "\n";
        }
    }
    
    return 0;
}
