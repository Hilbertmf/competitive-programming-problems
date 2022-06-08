// accepted
// https://codeforces.com/contest/1690/problem/D
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
        string s;
        cin >> s;

        queue<char> window;
        int windowCost = 0;
        for(int i = 0; i < k; ++i) {
            if(s[i] == 'W') windowCost++;
            window.push(s[i]);
        }

        int minCost = windowCost;

        for(int i = k; i < n; ++i) {
            char front = window.front();
            window.pop();
            if(front == 'W') windowCost--;
            window.push(s[i]);
            if(s[i] == 'W') windowCost++;

            minCost = min(minCost, windowCost);
        }

        cout << minCost << "\n";
    }
    
    
    return 0; 
}
