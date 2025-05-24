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
    string s, t;
    cin >> n >> s >> t;
    int colapses_in_t = 0;
    int superpositions = 0;

    for(int i = 0; i < n; ++i) {
        if (s[i] == '*')
            superpositions++;
        if (s[i] == '*' && t[i] != '*')
            colapses_in_t++;
    }

    double result = (double)(colapses_in_t) / superpositions;
    result *= 100;
    result = round(result);
    result /= 100;

    printf("%.2lf\n", result);

    return 0;
}
