// ac
// https://codeforces.com/contest/1988/problem/B
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
    
    while(t--){

        int n;
        cin >> n;
        vector<char> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<char> a1;

        for(int i = 0; i < n; ++i) {
            a1.push_back(a[i]);
            if (a[i] == '0') {

                int j;
                for(j = i; j < n && a[j] == '0'; ++j) { }
                if (j > i)
                    i = j - 1;
            }
        }

        int zeros = 0, ones = 0;
        for(int i = 0; i < a1.size(); ++i) {
            if (a1[i] == '0') zeros++;
            else ones++;
        }

        bool possible = ones > zeros;

        if(possible) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}
