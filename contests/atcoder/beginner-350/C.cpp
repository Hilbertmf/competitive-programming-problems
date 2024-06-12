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

    vector<int> nums(n);
    vector<int> idxs(n + 1);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        idxs[nums[i]] = i;
    }

    int op = 0;
    vector<pair<int, int>> operations;


    for(int i = 0; i < n - 1; ++i) {
        if (nums[i] != (i + 1)) {
            int pos = idxs[i + 1];
            operations.push_back({i + 1, pos + 1});
            idxs[nums[i]] = pos;
            swap(nums[i], nums[pos]);
        }
    }

    cout << operations.size() << "\n";
    for(auto &pair : operations) {
        cout << pair.first << " " << pair.second << "\n";
    }


    return 0;
}
