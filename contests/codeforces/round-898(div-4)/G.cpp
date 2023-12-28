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

        string s;
        cin >> s;
        int num_b = count(s.begin(), s.end(), 'B');
        int num_a = s.size() - num_b;
        vector<int> a_segs;
        int cnt = 0;

        for(int i = 0; i < s.size(); ++i) {
            
            while (i < s.size() && s[i] == 'A') {
                cnt++;
                i++;
            }
        
            if(cnt > 0)
                a_segs.push_back(cnt);
            cnt = 0;
        }

        if(num_b >= a_segs.size()) {
            cout << num_a << "\n";
        }
        else {
            cout << accumulate(a_segs.begin(), a_segs.end(), 0) - 
            *min_element(a_segs.begin(), a_segs.end()) << "\n";            
        }

    }
    
    return 0;
}
