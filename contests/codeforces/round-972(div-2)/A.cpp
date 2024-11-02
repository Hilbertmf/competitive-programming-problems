#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    string s = "aeiou";
    
    while(t--){

        int n;
        cin >> n;
        string ans;

        if(n <= 5) {
            for(int i = 0, j = 0; i < n; ++i, j = (j + 1) % 5) {
                ans += s[j];
            }
        }       
        else {
            int qnt = n / 5;
            vector<int> arr(5, qnt);
            int rem = n % 5;
            for(int i = 0; i < 5 && rem; ++i) {
                arr[i]++;
                rem--;
            }

            for(int i = 0; i < 5; ++i) {
                for(int j = 0; j < arr[i]; ++j) {
                    ans += s[i];
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
