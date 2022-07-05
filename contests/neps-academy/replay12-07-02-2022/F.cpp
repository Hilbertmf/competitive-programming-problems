// accepted
// https://neps.academy/br/competition/1356/exercise/1329
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
 
int main() { 
    FASTIO;
    int n;
    cin >> n;
    vector<int> fat(2);
    fat[0] = 1;
    fat[1] = 1;

    int factorial = 2;
    for(int i = 2; fat[i - 1] < n; ++i) {
        fat.push_back(i * fat.back());
    }

    int ans = 0;

    while(n) {
        auto low = lower_bound(fat.begin(), fat.end(), n);
        if(*low > n) --low;

        ans += n / *low;
        n %= *low;
    }

    cout << ans << "\n";
    
    return 0; 
}
