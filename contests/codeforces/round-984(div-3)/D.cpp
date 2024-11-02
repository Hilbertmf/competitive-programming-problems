// https://codeforces.com/contest/2036/problem/D
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

        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        vector<string> s;

        // travel
        for(int i = 0; i < n / 2 && i < m / 2; ++i) {
            
            string str;
            int c, r;

            for(c = i; c < m - i; ++c) {
                str += grid[i][c];
            }
            c--;

            
            for(r = i + 1; r < n - i; ++r) {
                str += grid[r][c];
            }

            r--;

            for(c = c - 1; c >= i; --c) {
                str += grid[r][c];
            }
            c++;


            
            for(r = r - 1; r >= i + 1; --r) {
                str += grid[r][c];
            }

            s.push_back(str);
        }

        int ans = 0;
        for(auto &str : s) {
            string pat = "1543";
            str += str.substr(0, 3);
            vector<int> z = z_func(pat, str);
            set<int> target_indices;
            for(int i = pat.size() + 1; i < z.size(); ++i) {
                if(z[i] == pat.size()) ans++;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
