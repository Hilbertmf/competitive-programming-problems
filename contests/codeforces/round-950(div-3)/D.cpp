// wa
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pprev __gcd(a[i - 3], a[i - 2])
#define nxt __gcd(a[i + 2], a[i + 3])
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int count = 0;
        bool ans = true;

        int prev = __gcd(a[0], a[1]);
        int curr = 1;

        if (__gcd(a[0], a[1]) > __gcd(a[1], a[2])) {
            count++;
            prev = curr;
        }
        
        /*
        prev = i - 1, i
        curr = i, i + 1
        nxt = i + 1, i + 2

                       pprev         prev      cur
        i - 3, i - 2 ; i - 2, i - 1; i - 1, i; i, i + 1
        i - 3, i - 2 ; i - 3, i - 2; i - 2, i; i, i + 1
        */

       set<int> removed_indices;

        for(int i = 2; i < n - 2; ++i, prev = curr) {
            curr = __gcd(a[i], a[i + 1]);

            if (prev > curr) {
                
                // remove i - 1
                if (i >= 2) {
                    prev = __gcd(a[i - 2], a[i]);
                    curr = __gcd(a[i], a[i + 1]);
                    if (prev <= curr &&
                        ((i >= 3 && prev >= pprev) ||
                        i < 3)) {
                        count++;
                        removed_indices.insert(i - 1);
                        continue;
                    }
                }
                
                // remove i
                prev = __gcd(a[i - 2], a[i - 1]);
                curr = __gcd(a[i - 1], a[i + 1]);
                if (prev <= curr) {
                    count++;
                    removed_indices.insert(i);
                    continue;
                }

                // remove i + 1
                if (i < n - 2) {
                    prev = __gcd(a[i - 1], a[i]);
                    curr = __gcd(a[i], a[i + 2]);
                    if (prev <= curr &&
                        (i < n - 3 && curr <= nxt) ||
                        i >= n - 3) {
                        count++;
                        i++;
                        removed_indices.insert(i + 1);
                        continue;
                    }
                }

                ans = false;
            }
        }

        prev = curr;

        if (n >= 4 &&
            __gcd(a[n - 3], a[n - 2]) > __gcd(a[n - 2], a[n - 1])) {
            count++;
        }
        
        if(ans && count <= 1) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }        
    }
    
    return 0;
}
