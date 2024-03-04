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

        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);
        for(auto &num : a) cin >> num;
        for(auto &num : b) cin >> num;
        unordered_set<int> a_set(a.begin(), a.end());
        unordered_set<int> b_set(b.begin(), b.end());

        bool possible = true;

        int count_a = 0, count_b = 0;
        int total = k;
        for(int i = 1; i <= k && possible; ++i) {

            if(a_set.find(i) == a_set.end() && b_set.find(i) == b_set.end()) {
                possible = false;
            }
            // only a
            else if(a_set.find(i) != a_set.end() && b_set.find(i) == b_set.end()) {
                count_a++;
            }
            // only b
            else if(b_set.find(i) != b_set.end() && a_set.find(i) == a_set.end()) {
                count_b++;
            }

            if (count_a > k / 2 || count_b > k / 2) {
                possible = false;
            }
        }

        total -= (count_a + count_b);
        int remaining_a = k / 2 - count_a;
        int remaining_b = k / 2 - count_b;
        if(remaining_a + remaining_b != total)
            possible = false;

        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }

    }
    
    return 0;
}
