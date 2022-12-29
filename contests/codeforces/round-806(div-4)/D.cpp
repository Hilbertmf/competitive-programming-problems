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
        vector<string> strs(n);
        unordered_set<string> strSetRev;
        strSetRev.reserve(n);
        for(int i = 0; i < n; ++i) {
            cin >> strs[i];
            string tmp = strs[i];
            reverse(tmp.begin(), tmp.end());
            strSetRev.insert(tmp);
        }
        unordered_set<string> strSet(strs.begin(), strs.end());

        string res;

        for(auto &str : strs) {
            if(str.size() == 1) {
                res += '0';
                continue;
            }

            string s;
            unordered_set<int> positionsFromLeft;
            for(int l = 1; l < str.size(); ++l) {
                s += str[l - 1];
                if(strSet.find(s) != strSet.end()) {
                    positionsFromLeft.insert(l);
                }
            }

            s.clear();
            string tmp = str;
            reverse(tmp.begin(), tmp.end());
            bool possible = false;
            for(int l = 1; l < str.size(); ++l) {
                s += tmp[l - 1];
                if(strSetRev.find(s) != strSetRev.end() &&
                positionsFromLeft.find((int)str.size() - l) != positionsFromLeft.end()) {
                    possible = true;
                    break;
                }				
            }
            
            if(possible) {
                res += '1';
            }
            else {
                res += '0';
            }
        }

        cout << res << "\n";
    }	
    
    return 0; 
}
