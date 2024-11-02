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

        int n, q, k, in_between = 0;
        cin >> n >> q;
        vector<int> x(n);
        for(int i = 0; i < n; ++i) cin >> x[i];

        vector<int> segs(n);
        map<int, int> count;

        if (n == 2) {
            segs = {1, 1};
            count[1] = 2;

            if (x[1] - x[0] > 1) {                
                in_between = x[1] - x[0] - 1;
                count[segs[0]] += in_between;
            }

        }
        else {
            int cur = n - 1;
            segs[0] = cur;
            segs[1] = cur + (cur - 1);
            cur += n - 2;
            count[segs[0]]++;

            if (x[1] - x[0] > 1) {                
                in_between = x[1] - x[0] - 1;
                count[segs[0]] += in_between;
            }

            count[segs[1]]++;
            int remove = 1;

            for(int i = 2; i < n; ++i) {
                if (x[i] - x[i - 1] > 1) {
                    int val = cur - remove;
                    in_between = x[i] - x[i - 1] - 1;
                    count[val] += in_between;
                }

                int dist = n - 1 - i;
                cur += dist;
                cur -= remove;
                segs[i] = cur;
                remove++;
                count[segs[i]]++;
            }
        }

        vector<int> output;
        while (q--) {
            cin >> k;
            if (count.count(k)) {
                output.push_back(count[k]);
            }
            else
                output.push_back(0);
        }
        for(int i = 0; i < output.size(); ++i) {
            if (i != 0) cout << " ";
            cout << output[i];
        }
        cout << "\n";
    }
    
    return 0;
}
