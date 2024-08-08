// https://codeforces.com/contest/1999/problem/A
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        string n;
        cin >> n;
        cout << (n[0] - '0') + (n[1] - '0') << "\n";
    }
    
    return 0;
}
