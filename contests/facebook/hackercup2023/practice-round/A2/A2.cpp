// https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/A2
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
#define int long long
const int MOD = 1000000007; // 10^9 - 7 
 
int32_t main() { 
	FASTIO;
    int t;
    cin >> t;
    int num_case = 1;
    while (t--) {
        int a, b, c;
        int ans;
        cin >> a >> b >> c;
        
        if(b >= 2 * a) {
            ans = c / a;
        }
        else {
            int num_b = c / b;
            if (num_b == 0) {
                ans = c / a;
            }
            else if(a > b) {
                ans = (num_b * 2) - 1;
            }
            else {
                c %= b;
                int n_a = c / a;
                ans = (num_b * 2) + (n_a == 0 ? -1 : 0) + n_a;
                n_a = (c + b) / a;
                ans = max(ans,
                        ((num_b - 1) * 2) + (n_a == 0 ? -1 : 0) + n_a);
            }
        }

        cout << "Case #" << num_case << ": ";
        cout << ans << "\n";
        num_case++;
    }
	
	return 0; 
}
