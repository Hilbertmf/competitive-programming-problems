// accepted
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b54d3b
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

bool canBePalindrome(vector<vector<int>>& prefixSumMap, int l, int r) {
    vector<int> tmpMap(26);

    for(int i = 0; i < 26; ++i) {
        tmpMap[i] = prefixSumMap[r][i];
        if(l > 0)
            tmpMap[i] -= prefixSumMap[l - 1][i];
    }

    int numOdd = 0;

    for(int i = 0; i < 26; ++i) {
        if(tmpMap[i] & 1) {
            numOdd++;
        }
    }

    return numOdd <= 1;
}

int main() { 
    FASTIO;
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; ++t) {
        int numBlocks, numQueries;
        cin >> numBlocks >> numQueries;
        string blocks;
        cin >> blocks;
        vector<vector<int>> prefixSumMap(numBlocks, vector<int>(26));
        
        prefixSumMap[0][blocks[0] - 'A']++;

        for(int i = 1; i < numBlocks; ++i) {
            prefixSumMap[i][blocks[i] - 'A']++;
            for(int j = 0; j < 26; ++j) {
                prefixSumMap[i][j] += prefixSumMap[i - 1][j];
            }
        }

        int ans = 0;

        while(numQueries--) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;

            if(canBePalindrome(prefixSumMap, l, r))
                ans++;
        }
        
        cout << "Case #" << t+1 << ": " << ans << "\n";
    }	
    return 0; 
}
