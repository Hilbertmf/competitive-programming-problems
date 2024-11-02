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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        int MAX = *max_element(a.begin(), a.end());
        vector<int> indices;
        for(int i = 0; i < n; ++i) {
            if (a[i] == MAX) {
                indices.push_back(i);
            }
        }

        int score = 0;
        for(auto &ind : indices) {
            int sum = 0;
            for(int i = ind; i < n; i += 2) {
                sum++;
            }
            for(int i = ind - 2; i >= 0; i -= 2) {
                sum++;
            }
            score = max(sum, score);
        }
        score += MAX;
        cout << score << "\n";

    }
    
    return 0;
}
