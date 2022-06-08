// accepted
// https://codeforces.com/contest/1690/problem/E
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
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> weights(n);
        multiset<pair<int, int>> modAndWeights;
        for(int i = 0; i < n; ++i) {
            cin >> weights[i];
            modAndWeights.insert({weights[i] % k, weights[i]});
        }
        
        long long totalCost = 0;

        for(const auto &weight : weights) {
            if(modAndWeights.find({weight % k, weight}) == modAndWeights.end())
                continue;

            int complement = k - (weight % k);
            auto low = modAndWeights.lower_bound({complement, 0});
            
            // low is pointing at weight pair
            if(low->first == (weight % k) && low->second == weight)
                ++low;
            if(low == modAndWeights.end() || low->first < complement)
                continue;
            
            totalCost += floor((weight + low->second) / (float)k);
            
            modAndWeights.erase(low);
            modAndWeights.erase(modAndWeights.find({weight % k, weight}));
        }

        for(auto it = modAndWeights.begin(); it != modAndWeights.end(); ++it) {
            auto nextIt = next(it);
            totalCost += floor((it->second + nextIt->second) / (float)k );
            ++it;
        }

        cout << totalCost << "\n";

    }

    return 0;
}