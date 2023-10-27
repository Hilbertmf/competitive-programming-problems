// https://codeforces.com/contest/1883/problem/D
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
const int MOD = 1000000007; // 10^9 - 7 
#define int long long

int32_t main() { 
    FASTIO;

    int q;
    cin >> q;

    multiset<vector<int>> set_left;
    multiset<vector<int>> set_right;

    for(int i = 0; i < q; ++i) {
        char op;
        cin >> op;
        int l, r;
        cin >> l >> r;

        if(op == '+') {
            set_left.insert({l, l, r});
            set_right.insert({r, l, r});
        }

        else {
            set_left.erase(set_left.find({l, l, r}));
            set_right.erase(set_right.find({r, l, r}));
        }

        int min_right = 0, max_left = 0;

        if(set_left.size() > 0 && set_right.size() > 0) {
            min_right = (*set_right.begin())[0];
            max_left = (*prev(set_left.end()))[0];
        }
        
        if(set_left.size() >= 2 && min_right < max_left) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }

    }        

    return 0;
}