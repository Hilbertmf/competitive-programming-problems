// accepted
// https://m2.codeforces.com/contest/1688/problem/B
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

int getPowersOf2(int n) {
    int numPowersOf2 = 0;
    while(!(n & 1)) {
        n /= 2;
        numPowersOf2++;
    }
    return numPowersOf2;
}

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> powers(n);
        int numOdd = 0, numEven = 0;
        int operations = 0;

        for(int i = 0; i < n; ++i) {
            cin >> powers[i];
            if(powers[i] & 1)
                numOdd++;
            else
                numEven++;
        }

        if(numEven == 0) {
            cout << operations << "\n";
        }
        else if(numOdd > 0) {
            cout << numEven << "\n";
        }
        else {
            int idx = 0;
            int minPowersOf2 = INF;
            for(int i = 0; i < n; ++i) {
                int numPowersOf2 = getPowersOf2(powers[i]);
                minPowersOf2 = min(minPowersOf2, numPowersOf2);
            }

            operations += minPowersOf2 + numEven - 1;
            cout << operations << "\n";
        }

    }	
    
    
    return 0; 
}
