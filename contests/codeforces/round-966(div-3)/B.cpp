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

        bool followed = true;
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }

        vector<char> seats(n);

        seats[a[0]] = true;
        for(int i = 1; i < n && followed; ++i) {
            int place = a[i];
            if (place == 0) {
                if (seats[place + 1] == false)
                    followed = false;
            }
            if (place == n - 1) {
                if (seats[place - 1] == false)
                    followed = false;
            }
            if (seats[place - 1] == false && seats[place + 1] == false) {
                followed = false;
            }

            seats[place] = true;
        } 


        if(followed) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
    
    return 0;
}
