// O(nlogn)
// https://codeforces.com/contest/1894/problem/C
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
const int MOD = 1000000007; // 10^9 - 7 
#define int long long

int32_t main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n+1);
        for(int i = 1; i <= n; ++i) cin >> b[i];

        int vertex = b[n];
        set<int> vis;
        int count = 0;
        bool possible = vertex == n; // if last == n then 1 operation does not change b
        int pos = n;

        if(vertex > n) count = -1;

        while(!possible && count >= 0 && vis.find(pos) == vis.end()) {
            int new_pos;
            if(vertex == n) {
                possible = true;
            }
            else if(vertex <= n) {
                if(pos > vertex)
                    new_pos = pos - vertex;
                else
                    new_pos = n - (vertex - pos);
                vertex = b[new_pos];
            }
            else {
                break;
            }
            vis.insert(pos);
            pos = new_pos;
        }

        possible |= vis.find(pos) != vis.end(); // goes indefinitely
        possible |= k <= vis.size();

        if(possible) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }

    return 0;
}