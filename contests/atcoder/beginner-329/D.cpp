// https://atcoder.jp/contests/abc329/tasks/abc329_d
// accepted
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long 
const int MOD = 1e9 + 7; // 10^9 + 7 
 
int32_t main() { 
    FASTIO;

    int n, m;
    cin >> n >> m;
    
    set<pair<int, int>> candidates;
    map<int, int> cand_map;

    for(int i = 1; i <= n; ++i) {
        candidates.insert({0, -i});
        cand_map[-i] = 0;
    }

    for(int i = 0; i < m; ++i) {
        int cand;	
        cin >> cand;
        int num_votes = cand_map[-cand];

        if(candidates.find({num_votes, -cand}) != candidates.end()) {
            candidates.erase(candidates.find({num_votes, -cand}));
        }
        candidates.insert({num_votes+1, -cand});
        cand_map[-cand]++;

        cout << -candidates.rbegin()->second << "\n";

    }


    return 0; 
}
