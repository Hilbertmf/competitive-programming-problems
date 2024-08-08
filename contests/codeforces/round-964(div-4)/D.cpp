// https://codeforces.com/contest/1999/problem/D
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    cin.ignore();
    while(t--){

        string s, t;

        getline(cin, s);
        getline(cin, t);

        bool pos = false;

        int i = 0, j = 0;
        for(i = 0; i < s.size() && j < t.size(); ++i) {
            if (j < t.size() &&
            (s[i] == t[j] || s[i] == '?')) {
                if (s[i] == '?')
                    s[i] = t[j];
                ++j;
            }
        }

        if (j == t.size())
            pos = true;

        for(auto &c : s) {
            if (c == '?') c = 'a';
        }

        if(pos) {
            cout << "YES\n" << s << "\n";
        }
        else {
            cout << "NO\n";            
        }
    }
    
    return 0;
}
