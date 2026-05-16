// AC
// https://codeforces.com/group/FOtuBenVgP/contest/692619
// https://codeforces.com/gym/105873/problem/E
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
    
    int n, m, num;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> num;
        if(num >= m){
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}
