// O(S.size)
// https://atcoder.jp/contests/abc328/tasks/abc328_d
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

    string s;
    cin >> s;
    stack<char> st;
    string tmp;

    for(char c : s) {
        if(st.size() >= 2 &&
        (tmp.size() >= 2 && tmp[tmp.size()-1] == 'B' && tmp[tmp.size()-2] == 'A' && c == 'C')) {
            st.pop();
            st.pop();
            tmp.pop_back();
            tmp.pop_back();
        }
        else {
            st.push(c);
            tmp += c;

        }

    }

    string ans;

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";

    return 0; 
}
