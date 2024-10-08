// accepted
// https://codeforces.com/contest/1676/problem/H1
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
        int length;
        cin >> length;
        vector<int> segments(length);
        for(int i = 0; i < length; ++i) cin >> segments[i];

        int numCrossings = 0;
        for(int i = 0; i < length; ++i) {
            for(int j = i + 1; j < length; ++j) {
                if(segments[i] >= segments[j])
                    numCrossings++;
            }
        }

        cout << numCrossings << "\n";
    }

    return 0;
}