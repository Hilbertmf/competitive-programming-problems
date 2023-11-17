// https://codeforces.com/contest/1899/problem/B
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

vector<int> getFactors(int n) {
    vector<int> factors;
    for(int i = 2; i*i <= n; ++i) {
        if(n % i == 0) {
            factors.push_back(i);
            if(n / i != i)
            factors.push_back(n / i);
        }
    }

    return factors;
}

int32_t main() { 
    FASTIO;
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);


        int maxN = 0, minN = LONGINF;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            maxN = max(a[i], maxN);
            minN = min(a[i], minN);
        }

        vector<int> prefix_sum(n);
        prefix_sum[0] = a[0];
        for(int i = 1; i < n; ++i) {
            prefix_sum[i] = a[i] + prefix_sum[i-1];
        }

        vector<int> factors = getFactors(n);
        factors.push_back(1);
        sort(factors.begin(), factors.end());

        int ans = 0;

        for(auto &factor : factors) {
            int minN = LONGINF;
            int maxN = 0;

            for(int i = 0; i < n; i += factor) {
                int curr_sum = 0;
                for(int j = 0; j < factor; ++j) {
                    curr_sum += a[i+j];
                }
                minN = min(minN, curr_sum);
                maxN = max(maxN, curr_sum);
            }

            ans = max(ans, abs(maxN - minN));
        }

        cout << ans << "\n";



    }

    return 0; 
}
