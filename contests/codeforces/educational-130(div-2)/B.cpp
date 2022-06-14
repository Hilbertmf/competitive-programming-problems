// accepted
// https://codeforces.com/contest/1697/problem/B
// time: O(q + n)
// space: O(n)
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
    int numItems, numQueries;
    cin >> numItems >> numQueries;
    
    vector<long long> items(numItems);
    for(int i = 0; i < numItems; ++i) cin >> items[i];
    sort(items.begin(), items.end());
    vector<long long> prefix(numItems);
    prefix[0] = items[0];
    for(int i = 1; i < numItems; ++i) {
        prefix[i] = prefix[i - 1] + items[i];
    }

    while(numQueries--) {
        long long x, y, sum = 0;
        cin >> x >> y;

        long long start = numItems - x;
        long long end = start + y;
        if(start - 1 >= 0)
            sum = prefix[end - 1] - prefix[start - 1];
        else
            sum = prefix[end - 1];
        cout << sum << "\n";
    }
    
    
    return 0; 
}
