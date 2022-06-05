// https://codeforces.com/contest/1688/problem/C
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
        int numOperations;
        cin >> numOperations;
        vector<string> sequence(numOperations * 2);
        for(int i = 0; i < sequence.size(); ++i) cin >> sequence[i];
        string finalStr;
        cin >> finalStr;
        unordered_multiset<string> sequenceSet(sequence.begin(), sequence.end());

        vector<int> lettersMap(26);
        for(const auto &str : sequence) {
            for(const auto &c : str) {
                lettersMap[c - 'a']++;
            }
        }

        for(const auto &c : finalStr) {
            lettersMap[c - 'a']++;
        }

        string answer = "";
        for(int i = 0; i < 26 && answer == ""; ++i) {
            char c = 'a' + i;
            string letter = {c};
            if((lettersMap[i] & 1) && sequenceSet.find((string)letter) != sequenceSet.end()) { // odd
                answer = letter;
            }
        }

        cout << answer << "\n";
    }

    
    return 0; 
}
