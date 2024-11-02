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

        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        priority_queue<int> heap(a.begin(), a.end());
        

        sort(a.rbegin(), a.rend());
        int ans = 0;

        while (!heap.empty()) {
            int cur = heap.top();
            heap.pop();
            ans += cur;
            vector<int> r;
            
            for(int i = 0; i < x - 1 && !heap.empty(); ++i) {
                if (heap.top() < cur) {
                    r.push_back(cur - heap.top());
                }
                heap.pop();
            }

            if (heap.empty()) break;

            sort(r.rbegin(), r.rend());

            for(int i = 0; i < r.size() && !heap.empty(); ++i) {
                int rem = r[i];

                vector<int> tmp;
                while (rem && !heap.empty()) {
                    int tp = heap.top();
                    heap.pop();
                    if (rem > tp) {
                        rem -= tp;
                        tp = 0;
                    }
                    else if (rem == tp) {
                        tp -= rem;
                        rem = 0;
                    }
                    else {
                       tp -= rem;
                       rem = 0;
                    }
                    
                    if (tp > 0) tmp.push_back(tp);
                }
                for(auto &num : tmp) {
                    heap.push(num);
                }
            }


        }

        cout << ans << "\n";
    }
    
    return 0;
}