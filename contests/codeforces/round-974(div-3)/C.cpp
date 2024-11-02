#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

int32_t main() {
    FASTIO;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end());
        int p = n / 2;
        int val = a[p];

        int x = 2 * n * val + 1 - sum;

        if (n <= 2) {
            cout << "-1\n";
        } else if (x < 0) {
            cout << "0\n";
        } else {
            cout << x << "\n";
        }
    }
    
    return 0;
}
