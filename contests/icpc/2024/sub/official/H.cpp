// WA
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<string> possibilities;

void backtrackN(string &n, string &cur, int sz, int idx) {
    if (cur.size() >= sz) {
        possibilities.push_back(cur);
        return;
    }

    if (n[idx] != '*') {
        cur += n[idx];
        backtrackN(n, cur, sz, idx + 1);
        cur.pop_back();
    } else {
        cur += '0';
        backtrackN(n, cur, sz, idx + 1);
        cur.pop_back();
        cur += '1';
        backtrackN(n, cur, sz, idx + 1);
        cur.pop_back();
    }
}

long long binaryToDecimal(const string &binary) {
    long long decimal = 0;
    for (char digit : binary) {
        decimal = (decimal * 2) + (digit - '0');
    }
    return decimal;
}

bool findDivisibleM(string &M, const long long N) {
    int idx = M.find('*');
    if (idx == string::npos) {
        return binaryToDecimal(M) % N == 0;
    }
    M[idx] = '0';
    if (findDivisibleM(M, N)) return true;
    M[idx] = '1';
    if (findDivisibleM(M, N)) return true;
    M[idx] = '*';
    return false;
}

int32_t main() {
    FASTIO;

    string M, N;
    cin >> M >> N;
    string cur;
    backtrackN(N, cur, N.size(), 0);

    for (const string &possibleN : possibilities) {
        long long decN = binaryToDecimal(possibleN);
        string tmp_M = M;
        if (decN != 0 && findDivisibleM(tmp_M, decN)) {
            cout << tmp_M << "\n";
            return 0;
        }
    }

    cout << M << "\n";

    return 0;
}
