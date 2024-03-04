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
    
    while(t--){

        int n;
        cin >> n;
        vector<int> trace(n);
        string ans;
        char curr = 'a';
        unordered_map<char, int> chars;
        for(int i = 0; i < 26; ++i) {
            chars['a' + i] = 0;
        }

        for(int i = 0; i < n; ++i) {
            int num;
            cin >> num;

            char c;
            for(int j = 0; j < 26; ++j) {
                if(chars['a' + j] == num) {
                    c = 'a' + j;
                    break;
                }
            }
            chars[c]++;
            ans += c;
        }
        

        cout << ans << "\n";
    }
    
    return 0;
}
