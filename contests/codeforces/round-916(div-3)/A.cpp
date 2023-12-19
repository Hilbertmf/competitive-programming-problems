// https://codeforces.com/contest/1914/problem/A
// accepted
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
    int t;
    cin >> t;
    map<char, int> mp;
    int aux = 1;
    for(int i = 1; i <= 26; ++i) {
        char c = 'A' + (i-1);
        mp[c] = i;
    }

    while(t--){

        int n;
        cin >> n;
        string s;
        cin >> s;

        map<char, int> problems;
        int ans = 0;
        set<char> solved;

        for(int i = 0; i < s.size(); ++i) {
            problems[s[i]]++;
            if(problems[s[i]] >= mp[s[i]] && solved.find(s[i]) == solved.end()) {
                ans++;
                solved.insert(s[i]);
            }
        }

        cout << ans << "\n";

    }
    
    return 0;
}
