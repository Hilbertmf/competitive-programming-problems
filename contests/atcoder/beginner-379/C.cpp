// https://atcoder.jp/contests/abc379/tasks/abc379_c
// AC
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

int getAPSum(int a1, int d, int n) {
    return ((2*a1 + (n - 1) * d) * n) / 2;
}

int32_t main() {
    FASTIO;

    int n, m, ans = 0, num_stones = 0;
    cin >> n >> m;
    vector<int> x(m);
    map<int, int> stones;
    for(int i = 0; i < m; ++i) cin >> x[i];
    for(int i = 0; i < m; ++i) {
        int input;
        cin >> input;
        stones[x[i]] = input;
        num_stones += input;
    }

    if(num_stones != n) {
        cout << "-1\n";
    }
    else {

        bool possible = true;
        int cur_stones = 0, carry = 0;
        vector<pair<int, int>> pairs;
        for(auto &[k, v] : stones) pairs.push_back({k ,v});

        for(int i = 0; i < pairs.size() && possible; ++i) {
            auto [cell, stone] = pairs[i];
            int nxt_cell, nxt_stone;
            if (i < pairs.size() - 1) {
                nxt_cell = pairs[i + 1].first;
                nxt_stone = pairs[i + 1].second;
            }
            carry += stone - 1;
            cur_stones += stone;
            if (cell == n) {
                if (carry > 1) possible = false;
                break;
            }

            int dist = nxt_cell - cell;
            if (i == pairs.size() - 1) dist = n - cell;
            if (i == 0 && cell != 1 || dist - 1 > carry)
                possible = false;

            ans += getAPSum(carry, -1, dist);
            carry += ((dist - 1) * (-1));

            if (cur_stones < cell || (cell == n && (stone > 1 || carry > 1)))
                possible = false;
        }

        if(possible)
            cout << ans << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}
