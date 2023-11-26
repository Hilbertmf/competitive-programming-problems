// accepted
// https://open.kattis.com/problems/ultimatebinarywatch
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

    string s;
    cin >> s;

    vector<vector<char>> out(4, vector<char>(4));

    for(int r = 0; r < 4; ++r) {
        for(int i = 0; i < 4; ++i) {
            out[r][i] = '.';
            int num = s[i] - '0';
            num >>= 3 - r;
            if(num & 1)
                out[r][i] = '*';
        }
    }

    for(int r = 0; r < 4; ++r) {
        for(int c = 0; c < 4; ++c) {
            if(c != 0)
                cout << " ";
            cout << out[r][c];
            if(c == 1)
            cout << "  ";
        }
            cout << "\n";
    }

    return 0;
}
