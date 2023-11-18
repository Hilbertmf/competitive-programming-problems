// https://atcoder.jp/contests/abc329/tasks/abc329_c
// accepted
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long 
const int MOD = 1e9 + 7; // 10^9 + 7 
 
int32_t main() { 
    FASTIO;

    int n;
    cin >> n;
    string s;
    cin >> s;

    set<pair<char, int>> substrings;
    substrings.insert({s[0], 1});
    int char_count = 1;

    for(int i = 1; i < n; ++i) {
        if(s[i] != s[i-1]) {
            char_count = 0;
        }
        char_count++;
        substrings.insert({s[i], char_count});
    }

    cout << substrings.size() << "\n";

    return 0; 
}
