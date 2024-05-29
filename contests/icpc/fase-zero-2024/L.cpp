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

    int n;
    cin >> n;
    vector<string> children(n);
    set<pair<int, string>> youngest;
    unordered_map<string, int> children_ages;
    children_ages.reserve(n);

    for(int i = 0; i < n; ++i)
        cin >> children[i];
    for(int i = 0; i < n; ++i) {
        string child;
        cin >> child;
        youngest.insert({i, child});
        children_ages[child] = i;
    }

    for(int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << youngest.begin()->second;
        youngest.erase(youngest.find({children_ages[children[i]], children[i]}));
    }
    cout << "\n";

    return 0;
}
