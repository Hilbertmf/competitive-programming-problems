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

        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string s;
        cin >> s;

        int l = 0, r = n - 1;
        int sum = 0;
        vector<int> prefix(n);
        prefix[0] = a[0];
        for(int i = 1; i < n; ++i) {
            prefix[i] = a[i] + prefix[i - 1];
        }

        int count_l = count(s.begin(), s.end(), 'L');
        int count_r = count(s.begin(), s.end(), 'R');

        while (l < r) {
            while (l < n && s[l] != 'L' && l < r) l++;
            while (r >= 0 && s[r] != 'R' && l < r) r--;

            if (l >= r) break;

            sum += prefix[r];
            if (l > 0) sum -= prefix[l - 1];

            l++;
            r--;
        }

        cout << sum << "\n";
    }
    
    return 0;
}
