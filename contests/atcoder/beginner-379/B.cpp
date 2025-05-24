// https://atcoder.jp/contests/abc379/tasks/abc379_b
// AC
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
    FASTIO;

    int n, k, count = 0;
    cin >> n >> k;
    string s;
    cin >> s;

    int healthy = 0;
    for(auto &c : s) {
        if (c == 'O') healthy++;
        else healthy = 0;
        if (healthy == k) {
            count++;
            healthy = 0;
        }
    }

    cout << count << "\n";

    return 0;
}
