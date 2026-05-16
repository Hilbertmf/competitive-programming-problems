// https://codeforces.com/group/FOtuBenVgP/contest/692619
// https://codeforces.com/group/FOtuBenVgP/contest/692619/problem/H
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

// Z Algorithm
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

int get_score(string pattern, string& txt, int op) {
    vector<int> z = z_func(pattern, txt);
    int res = 0;
    for(auto item : z) {
        if (item == pattern.size()) res += op;
    }
    return res;
}

int32_t main() {
    FASTIO;

    string txt;
    int ans = 0;
    cin >> txt;

    ans += get_score("ha", txt, 1);
    ans += get_score("boooo", txt, -1);
    ans += get_score("bravo", txt, 3);    
    cout << ans << "\n";

    return 0;
}
