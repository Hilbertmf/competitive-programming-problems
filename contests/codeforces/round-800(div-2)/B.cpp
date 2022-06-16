// accepted
// https://codeforces.com/contest/1694/problem/B
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
        string s;		
        cin >> n;
        cin >> s;

        bool found1 = false;
        bool found0 = false;
        long long ans = s.size();
        long long sum = 0;

        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == '1') {
                found1 = true;
            }
            else {
                found0 = true;
            }
            if((found0 || found1) && (i < n - 1 && s[i + 1] != s[i])) {
                sum++;				
            }
            if(found1 && found0)
                ans += sum;
        }

        cout << ans << "\n";
    }	
    
    
    return 0; 
}
