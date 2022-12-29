// accepted
// https://codeforces.com/contest/1702/problem/D
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
        long long p;
        cin >> s >> p;
        map<char, long long> prices;
        vector<int> letters(26);
        int tmp = 1;
        for(char c = 'a'; c <= 'z'; ++c, ++tmp) {
            prices[c] = tmp;
        }
        
        long long price = 0;
        unordered_map<char, int> charsToRemove;
        for(auto &c : s) {
            price += prices[c];
            letters[c - 'a']++;
        }

        if(p >= price) {
            cout << s << "\n";
            continue;
        }
        
        long long removed = 0;

        for(int i = 26 - 1; i >= 0 && removed < (price - p); --i) {
            if(letters[i] == 0) continue;

            if(removed + (prices['a' + i] * letters[i]) > price - p) {
                long long comp = (price - p) - removed;
                long long numChars = ceil(comp / (double)prices['a' + i]);
                
                removed += numChars * prices['a' + i];
                charsToRemove['a' + i] = numChars;
            }
            else {
                removed += prices['a' + i] * letters[i];
                charsToRemove['a' + i] = letters[i];
            }
        }

        string res;
        for(auto &c : s) {
            if(charsToRemove.find(c) != charsToRemove.end() &&
            charsToRemove[c]) {
                charsToRemove[c]--;
            }
            else {
                res += c;
            }
        }

        cout << res << "\n";
    }	
    
    return 0; 
}
