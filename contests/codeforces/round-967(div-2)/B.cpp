// https://codeforces.com/contest/2001/problem/B
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        if(n % 2 == 0) {
            cout << "-1\n";
        }
        else {
            vector<int> p(n);
            int num = 1, l, r;
            for (l = 0, r = n - 1; l < r; l++, r--) {
                p[r] = num;
                num++;
                p[l] = num;
                num++;
            }
            p[l] = num;

            for(int i = 0; i < n; ++i) {
                if (i > 0) cout << " ";
                cout << p[i];
            }
            cout <<"\n";
        }
    }
    
    return 0;
}
