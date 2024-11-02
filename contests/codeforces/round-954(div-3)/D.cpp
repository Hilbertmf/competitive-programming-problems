#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

set<int> results;

int getSum(string& s, int pos) {
    int n = s.size() - 1;
    int sum = s[0] - '0', idx = 1;
    if (pos == 0) {
        sum = (s[0] - '0') * 10 + (s[1] - '0');
        idx = 2;
    }
    
    int MIN_SUM = -1;
    if (!results.empty())
        MIN_SUM = *results.begin();

    for(int i = 0; idx < s.size(); ++i, ++idx) {
        if (MIN_SUM != -1 && sum > MIN_SUM)
            return MIN_SUM;
        
        int nxt;
        if (idx == pos) {
            nxt = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
            idx++;
        }
        else
            nxt = s[idx] - '0';
                
        if (sum == 1 || sum == 0 || nxt == 1 || nxt == 0)
            sum *= nxt;
        else
            sum += nxt;

        if (sum == 0) return sum;
    }
    
    results.insert(sum);
    return sum;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        results.clear();
        int n;
        cin >> n;
        string s;
        cin >> s;

        int sum = INF;

        if (s.size() > 2) {
            
            for(int i = 0; i < n - 1; ++i) {
                int curr = getSum(s, i);
                sum = min(sum, curr);
            }
        }
        else {
            sum = (s[0] - '0') * 10 + (s[1] - '0');
        }        

        cout << sum << "\n";
    }
    
    return 0;
}
