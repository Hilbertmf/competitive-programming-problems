// https://codeforces.com/contest/1913/problem/A
// accepted
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

int main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        string s;
        cin >> s;
        bool pos = false;

        for(int i = 1; i < s.size(); ++i) {
            string a_str = s.substr(0, i);
            string b_str = s.substr(i);
            int a, b;
            a = stoi(a_str);
            if(!b_str.empty())
                b = stoi(b_str);

            if(b_str.empty() || a_str[0] == '0' || b_str[0] == '0')
                continue;
            if(b > a) {
                cout << a << " " << b << "\n";
                pos = true;
                break;
            }

        }
        
        if(!pos)
            cout << -1 << "\n";
    }
    
    return 0;
}
