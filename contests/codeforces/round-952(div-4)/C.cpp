// acc
// https://codeforces.com/contest/1985/problem/C
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
        vector<int> arr(n);
        int count = 0;
        int sum = 0;
        bool past = false;
        multiset<int> st;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
            st.insert(arr[i]);
            sum += arr[i];
            if (i == 0 && arr[i] == 0) {
                count++;
                past = true;
            }
            else if (i > 0) {
                int num = *st.rbegin();
                if (num == sum - num) {
                    count++;
                    past = true;
                }
                else if (num == 0 && past) {
                    count++;
                }
                else {
                    past = false;
                }
            }
        }

        cout << count << "\n";
    }
    
    return 0;
}
