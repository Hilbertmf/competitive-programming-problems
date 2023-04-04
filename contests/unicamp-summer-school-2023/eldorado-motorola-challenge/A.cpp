// acc
// contest: https://vjudge.net/contest/540086#overview
#include <bits/stdc++.h> 
using namespace std;
#define INF 1e18
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define int long long

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int in1 = 0;
    int in2 = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        in1 += a[i] != 1;
        in2 += a[i] != 2;
    }
        
    int ans = 0;

    for(int i = 0; i < k; ++i) {
        int num1 = a[i] == 1;
        int num2 = a[i] == 2;
        for(int j = i+k; j < n; j += k) {
            num1 += a[j] == 1;
            num2 += a[j] == 2;
        }
        ans += min(num1, num2);
    }

    cout << ans << "\n";
    
    return 0;
}