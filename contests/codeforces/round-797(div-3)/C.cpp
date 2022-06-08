// accepted
// https://codeforces.com/contest/1690/problem/C
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
        int n;
        cin >> n;
        vector<int> taskGivenTime(n);
        vector<int> taskEndTime(n);
        vector<int> durations(n);
        for(int i = 0; i < n; ++i) cin >> taskGivenTime[i];
        for(int i = 0; i < n; ++i) cin >> taskEndTime[i];

        durations[0] = taskEndTime[0] - taskGivenTime[0];
        for(int i = 1; i < n; ++i) {
            int start;
            if(taskGivenTime[i] > taskEndTime[i - 1])
                start = taskGivenTime[i];
            else
                start = taskEndTime[i - 1];
            int duration = taskEndTime[i] - start;
            durations[i] = duration;
        }

        for(int i = 0; i < n; ++i) {
            cout << durations[i];
            if(i != n - 1)
                cout << " ";
        }
        cout << "\n";
    }
    
    
    return 0; 
}
