// TLE
// https://neps.academy/br/competition/1356/exercise/1325
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
    int days, fee;
    cin >> days >> fee;
    vector<int> prices(days);

    for(int i = 0; i < days; ++i) cin >> prices[i];

    
    bool increasing = false, decreasing = false;
    int bought = prices[0], sold = 0;
    int profit = 0;

    int prev = prices[0];

    vector<int> profits(days+1);

    for(int i = 1; i < days; ++i) {
        profits[i] = profits[i - 1];

        if(prices[i] > prices[i-1]) {
            for(int j = 0; j < i; ++j) {
                profits[i] = max(profits[i], prices[i] - (prices[j] + fee) + profits[j]);
            }
        }
    }

    cout << profits[days - 1];
    return 0; 
}
