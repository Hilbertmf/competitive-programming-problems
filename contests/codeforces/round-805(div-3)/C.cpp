// accepted
// https://codeforces.com/contest/1702/problem/C
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
        int numStations, numQueries;
        cin >> numStations >> numQueries;
        vector<int> stations(numStations);
        map<int, int> smallIdxs;
        map<int, int> largeIdxs;
        for(int i = 0; i < numStations; ++i) {
            cin >> stations[i];
            smallIdxs[stations[i]] = INF;
            largeIdxs[stations[i]] = -INF;
        }

        for(int i = 0; i < numStations; ++i) {
            smallIdxs[stations[i]] = min(smallIdxs[stations[i]], i);
            largeIdxs[stations[i]] = max(largeIdxs[stations[i]], i);
        }

        
        while(numQueries--) {
            int s1, s2;
            cin >> s1 >> s2;

            if(smallIdxs.find(s1) == smallIdxs.end() || smallIdxs.find(s2) == smallIdxs.end()) {
                cout << "NO" << "\n";
                continue;
            }
            if(smallIdxs[s1] < largeIdxs[s2]) {
                cout << "YES" << "\n";
            }
            else
                cout << "NO" << "\n";
        }
    }	
    
    return 0; 
}
