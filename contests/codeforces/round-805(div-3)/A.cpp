// accepted
// https://codeforces.com/contest/1702/problem/A
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
 
int main() { 
    FASTIO;
    int t;
    cin >> t;
    vector<int> powers(10);
    powers[0] = 1;
    for(int i = 1; i < powers.size(); ++i) {
        powers[i] = powers[i - 1] * 10;
    }

    while (t--) {
        int price;
        cin >> price;
        auto low = lower_bound(powers.begin(), powers.end(), price);
        if(*low > price) low--;
        int closest = *low;
        cout << price - closest << "\n";
    }	
    
    return 0; 
}
