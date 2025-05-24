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

    vector<int> sorted {1, 2, 3, 4, 5};
    vector<int> v(5);
    for(int i = 0; i < 5; ++i) {
        cin >> v[i];
    }

    bool possible = false;
    for(int i = 0; i < 4 && !possible; ++i) {
        swap(v[i], v[i + 1]);
        if (v == sorted) {
            possible = true;
            break;
        }
        swap(v[i], v[i + 1]);
    }

    if(possible) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }


    return 0;
}
