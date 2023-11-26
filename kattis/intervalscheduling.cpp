// accepted
// https://open.kattis.com/problems/intervalscheduling
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define left(x) x[0]
#define right(x) x[1]
const int MOD = 1e9 + 7; // 10^9 + 7

bool intersect(vector<int>& v1, vector<int>& v2) {
    return right(v1) > left(v2);
}

int32_t main() {
    FASTIO;
    int n;
    int ans = 1;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    sort(intervals.begin(), intervals.end());

    vector<int> curr {left(intervals[0]), right(intervals[0])};

    for(int i = 1; i < n; ++i) {
        if(intersect(curr, intervals[i]) &&
        right(intervals[i]) < right(curr)) {
            curr = intervals[i];
        }
        else if(!intersect(curr, intervals[i])){
            curr = intervals[i];
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
