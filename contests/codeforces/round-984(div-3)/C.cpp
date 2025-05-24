// https://codeforces.com/contest/2036/problem/C
// AC
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

// time: O(n)
// space: O(n)
int advance_right(string& s, int left, int right) {
    while(right < s.size() && s[right - left] == s[right]) {
        ++right;
    }
    --right;
    return right;
}

vector<int> z_func(string& pattern, string& text) {

    string s = pattern + "$" + text;
    vector<int> z(s.size());
    int left = 0, right = 0;

    for(int i = 1; i < s.size(); ++i) {
        if(i > right) {
            left = right = i;
            right = advance_right(s, left, right);
            z[i] = right - left + 1;
        }
        else { // inside z-box
            // position inside the box compared to pattern
            int i1 = i - left;
            // if i can't touch right border of z-box
            if(z[i1] + i - 1 < right) {
                z[i] = z[i1];
            }
            else {
                // reset z-box and try to expand it
                left = i;
                right = advance_right(s, left, right);
                z[i] = right - left + 1;
            }
        }
    }
    return z;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        string s;
        cin >> s;
        int q, i, v;
        cin >> q;
        string pat = "1100";
        bool has = false;

        vector<int> z = z_func(pat, s);
        set<int> target_indices;
        for(int i = pat.size() + 1; i < z.size(); ++i) {
            if(z[i] == pat.size()) {
                has = true;
                target_indices.insert(i - pat.size() - 1);
            }
        }

        while (q--) {
            cin >> i >> v;

            --i;

            int cur = s[i] - '0';
            for(int j = i, k = 0; j >= 0 && k < 4; --j, ++k) {
                if (target_indices.count(j)) {
                    if (cur != v) {
                        target_indices.erase(j);
                    }
                }
            }

            char c = (char)(v + '0');
            s[i] = c;
            for(int j = i, k = 0; j >= 0 && k < 4; --j, ++k) {
                string tmp = s.substr(j, 4);
                if (tmp == "1100") {
                    target_indices.insert(j);
                }
            }
            for(int j = i + 1, k = 0; j < s.size() && k < 4; ++j, ++k) {
                if (s.size() - j < 4) continue;
                string tmp = s.substr(j, 4);
                if (tmp == "1100") {
                    target_indices.insert(j);
                }
            }

            has = !target_indices.empty();

            if(has) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
    
    return 0;
}
