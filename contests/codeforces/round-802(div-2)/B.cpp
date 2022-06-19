// accepted
// https://codeforces.com/contest/1700/problem/B
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

string diff(string s1, string s2) {
    string ans;

    int diff = s1.size() - s2.size();
    int carry = 0;
 
    for (int i = s2.size() - 1; i >= 0; i--) {
        int sub = ((s1[i + diff] - '0') - (s2[i] - '0')
                   - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        ans.push_back(sub + '0');
    }
 
    for (int i = s1.size() - s2.size() - 1; i >= 0; i--) {
        if (s1[i] == '0' && carry) {
            ans.push_back('9');
            continue;
        }
        int sub = ((s1[i] - '0') - carry);
            ans.push_back(sub + '0');
        carry = 0;
    }
 
    reverse(ans.begin(), ans.end());
 
    return ans;
}

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int len;
        string s;
        cin >> len >> s;

        string ans;
        string target;

        if(s[0] == '9') {
            for(int i = 0; i < len + 1; ++i) {
                target += '1';
            }
            
        }
        else {
            for(int i = 0; i < len; ++i) {
                target += '9';
            }
        }
        ans = diff(target, s);

        // remove left zeros
        int idx = 0;
        while(ans[idx] == '0') ++idx;
        ans = ans.substr(idx);

        cout << ans << "\n";
    }	
    
    return 0; 
}
