#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<vector<int>> prefix(3);

vector<pair<int, int>> ans(3);

bool f(int first, int sec, int third, int target) {
    int n = prefix[0].size();

    auto it1 = lower_bound(prefix[first].begin(), prefix[first].end(), target);
    if (it1 == prefix[first].end())
        return false;
    int r1 = it1 - prefix[first].begin();

    if (r1 >= n - 2)
        return false;
    
    int start2 = prefix[sec][r1];
    int target2 = target + start2;
    if (prefix[sec].back() < target2)
        return false;
    auto it2 = lower_bound(prefix[sec].begin(), prefix[sec].end(), target2);
    if (it2 == prefix[sec].end())
        return false;
    int r2 = it2 - prefix[sec].begin();
    if (r2 >= n - 1)
        return false;
    
    int start3 = prefix[third][r2];
    int target3 = start3 + target;
    if (prefix[third].back() < target3)
        return false;
    auto it3 = lower_bound(prefix[third].begin(), prefix[third].end(), target3);
    if (it3 == prefix[third].end())
        return false;
    int r3 = it3 - prefix[third].begin();
    
    ans[first] = {0, r1};
    ans[sec] = {r1 + 1, r2};
    ans[third] = {r2 + 1, r3};
    return true;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        for(int i = 0; i < n; ++i) cin >> c[i];

        int sum = 0;
        sum = accumulate(a.begin(), a.end(), sum);
        prefix[0].resize(n);
        prefix[1].resize(n);
        prefix[2].resize(n);

        prefix[0][0] = a[0];
        prefix[1][0] = b[0];
        prefix[2][0] = c[0];
        for(int i = 1; i < n; ++i) {
            prefix[0][i] = a[i] + prefix[0][i - 1];
        }
        for(int i = 1; i < n; ++i) {
            prefix[1][i] = b[i] + prefix[1][i - 1];
        }
        for(int i = 1; i < n; ++i) {
            prefix[2][i] = c[i] + prefix[2][i - 1];
        }

        int target = ceil((double)sum / 3.0);

        bool possible = f(0, 1, 2, target);

        if (!possible)
            possible |= f(0, 2, 1, target);
        if (!possible)
            possible |= f(1, 0, 2, target);
        if (!possible)
            possible |= f(1, 2, 0, target);
        if (!possible)
            possible |= f(2, 0, 1, target);
        if (!possible)
            possible |= f(2, 1, 0, target);


        if(possible) {
            for(int i = 0; i < 3; ++i) {
                if (i > 0)
                    cout << " ";
                cout << ans[i].first + 1 << " " << ans[i].second + 1;
            }
            cout << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    
    return 0;
}
