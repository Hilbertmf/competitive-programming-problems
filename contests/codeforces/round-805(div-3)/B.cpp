// accepted
// https://codeforces.com/contest/1702/problem/B
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
        string s;
        cin >> s;
        unordered_set<char> letters;
        int days = 1;

        int i = 0;
        while(i < s.size()) {
            letters.insert(s[i]);
            if(letters.size() > 3) {
                letters.clear();
                letters.insert(s[i]);
                days++;
            }
            i++;
        }

        cout << days << "\n";
    }	
    
    return 0; 
}
