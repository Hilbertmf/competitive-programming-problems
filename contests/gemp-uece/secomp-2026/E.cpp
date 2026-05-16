// AC
// https://codeforces.com/group/FOtuBenVgP/contest/692619
// https://codeforces.com/gym/105873/problem/D
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

    int k, n, stop_day = INF, stop_order = -1;
    bool stop_at_day1 = false, found = false;
    cin >> k;
    vector<int> a(k);

    for(int i = 0; i < k; ++i)
        cin >> a[i];
    cin >> n;

    vector<vector<int>> orders(n, vector<int>(k));
    vector<int> sums(k);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < k; ++j) {
            cin >> orders[i][j];
            sums[j] += orders[i][j];
        }
    }

    for(int i = 0; i < k; ++i) {
        if (sums[i] > a[i]) {
            stop_at_day1 = true; break;
        }
        int q = INF;
        if (sums[i] != 0)
            q = a[i] / sums[i];
        stop_day = min(stop_day, q);
    }

    if (!stop_at_day1) {
        for(int i = 0; i < k; ++i) {
            a[i] = a[i] - (sums[i] * stop_day);
        }
    }
    
    for(int i = 0; i < n && !found; ++i) {
        for(int j = 0; j < k && !found; ++j) {
            
            a[j] -= orders[i][j];
            if (a[j] < 0) {
                stop_order = i;
                found = true;
                break;
            }
        }
    }

    if(stop_at_day1) {
        stop_day = 0;
    }
    cout << stop_day + 1 << " " << stop_order + 1 << "\n";

    return 0;
}
