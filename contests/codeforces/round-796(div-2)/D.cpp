// accepted
// https://codeforces.com/contest/1688/problem/D
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

long long maxll(long long a, long long b) {
    if(a > b) return a;
    return b;
}

long long minll(long long a, long long b) {
    if(a > b) return b;
    return a;
}

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> mushrooms(n);
        for(auto &mushroom : mushrooms) cin >> mushroom;
        
        long long result = 0;
        queue<long long> window;
        long long sum = 0;
        int i = 0;
        
        for(; i < k && i < mushrooms.size(); ++i) {
            sum += mushrooms[i];
            window.push(mushrooms[i]);
        }

        // get max window sum
        long long maxSum = sum;
        for(; i < mushrooms.size(); ++i) {
            sum -= window.front();
            window.pop();
            sum += mushrooms[i];
            window.push(mushrooms[i]);
            maxSum = maxll(maxSum, sum);
        }

        // arithmetic progression w/ min(k, n)
        long long aux  = minll(k, n);
        result = maxSum + (aux * aux - aux) / 2;
        
        if(k > n) {
            result += k - n;
            result += (k - n) * (n - 1);
        }
        cout << result << "\n";	
    }
    
    return 0; 
}
