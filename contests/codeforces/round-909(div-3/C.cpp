// https://codeforces.com/contest/1899/problem/C
// accepted
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long 
const int MOD = 1e9 + 7; // 10^9 + 7 

int32_t main() { 
    FASTIO;
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        bool all_neg = true;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] > 0) all_neg = false;
        }

        int ans = *max_element(a.begin(), a.end());

        if(!all_neg) {
            int start = 0;
            int end = n - 1;

            while (start < n && a[start] <= 0) {
                start++;
            }

            int curr_sum = a[start];
            int parity_last = a[start] % 2 == 0;
            ans = max(ans, curr_sum);


            for(int i = start + 1; i <= end; ++i) {
                ans = max(ans, curr_sum);
                int curr_parity = a[i] % 2 == 0;
                if(curr_parity == parity_last || curr_sum <= 0) {
                    while (i <= end && a[i] <= 0) {
                        i++;
                    }
                    if(i < n) {
                        curr_sum = a[i];
                        parity_last = a[i] % 2 == 0;
                    }
                }
                else {
                    curr_sum += a[i];
                    parity_last = curr_parity;
                }
                ans = max(ans, curr_sum);
            }
            ans = max(ans, curr_sum);

        }

        cout << ans << "\n";



    }

    return 0; 
}