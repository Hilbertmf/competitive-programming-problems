#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define INF_DOUBLE numeric_limits<long double>::max()
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int dist(pair<int, int>& x, pair<int, int>& y) {
    int a = abs(x.first - y.first);
    int b = abs(x.second - y.second);
    return a*a + b*b;
}

long double getTime(vector<int>& sequence,
vector<vector<pair<int, int>>>& segments, long double S, long double T) {
    pair<int, int> cur = {0, 0};
    vector<vector<pair<int, int>>> tmp;
    for(int i = 0; i < sequence.size(); ++i) {
        tmp.push_back(segments[sequence[i]]);
    }
    long double time = 0;

    for(auto &segment : tmp) {
        int d = dist(cur, segment[0]);
        cur = segment[1];

        time += sqrtl(d) / S;
        int d2 = dist(segment[0], segment[1]);
        time += sqrtl(d2) / T;
    }
    return time;
}

long double backtrack(vector<int>& sequence,
vector<vector<pair<int, int>>>& segments, int pos, int n, long double S, long double T) {
    if (pos >= n) {
        return getTime(sequence, segments, S, T);
    }

    long double result = backtrack(sequence, segments, pos + 1, n, S, T);
    swap(segments[pos][0], segments[pos][1]);
    result = min(result, backtrack(sequence, segments, pos + 1, n, S, T));
    return result;
}

int32_t main() {
    FASTIO;

    int n, s, t, a, b, c, d;
    cin >> n >> s >> t;
    vector<int> seq;
    vector<vector<pair<int, int>>> segments(n);
    for(int i = 0; i < n; ++i) {
        seq.push_back(i);
        cin >> a >> b >> c >> d;
        segments[i] = {{a, b}, {c, d}};
    }
        
    long double ans = numeric_limits<long double>::max();
    // all permutations
    while (true) {

        long double cur = backtrack(seq, segments, 0, n, (long double)s, (long double)t);

        ans = min(ans, cur);
        if (!next_permutation(seq.begin(), seq.end())) {
            break;
        }
    }
    cout << fixed << setprecision(7);
    cout << ans << "\n";

    return 0;
}
