#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

long double getCost(pair<long double, long double>& p1, pair<long double, long double>& p2) {
    return ((p1.first - p2.first) * (p1.first - p2.first)) +
           ((p1.second - p2.second) * (p1.second - p2.second));
}

int32_t main() {
    FASTIO;

    int n;
    cin >> n;
    vector<pair<long double, long double>> points(n);
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    pair<long double, long double> cur = {0, 0};
    long double ans = 0;

    for(auto &point : points) {
        ans += sqrtl(getCost(cur, point));
        
        cur = point;

    }

    pair<long double, long double> end = {0, 0};
    ans += sqrtl(getCost(cur, end));
    cout << fixed << setprecision(6);
    cout << ans << "\n";

    return 0;
}
