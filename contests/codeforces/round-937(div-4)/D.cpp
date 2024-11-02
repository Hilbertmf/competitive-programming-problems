#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

set<int> goods;

bool isGood(int n) {
    if (goods.find(n) != goods.end())
        return true;
    string str = to_string(n);
    bool ret = true;
    for(char c : str) {
        if (c != '1' && c != '0') {
            ret = false;
            break;
        }
    }
    if (ret) goods.insert(n);
    return ret;
}

bool hasGoodFactors(int n) {
    for(int i = 2; i * i <= n && !isGood(n); ++i) {
        if (n % i == 0) {
            int div = n / i;

            if (div != i && isGood(div)) {
                while (n % div == 0 && !isGood(n)) {
                    n /= div;
                }
            }

            if (isGood(i)) {
                while (n % i == 0 && !isGood(n)) {
                   n /= i;
                }
            }


        }
    }

    return isGood(n);
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;

        if(hasGoodFactors(n)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }

    }
    
    return 0;
}
