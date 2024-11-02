#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int solve(vector<int>& arr, int n, int k) {
    sort(arr.begin(), arr.end());
 
    int L = 0;
    int R = arr[n - 1] + k + 1;
 
    while (L + 1 < R) {
        int mid = MID(L, R);
        int need = 0;
 
        for (int i = 0; i < n; i++) {
            if (arr[i] < mid) {
                need += mid - arr[i];
            }
        }
        if (need <= mid && need <= k) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    return L;
}


int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, k, num;
        cin >> n >> k;
        map<int, int> cards_mp;
        vector<int> card_counts;
        for(int i = 0; i < n; ++i) {
            cin >> num;
            cards_mp[i] = num;
            card_counts.push_back(num);
        }

        cout << solve(card_counts, n, k) << "\n";

        // sort(card_counts.rbegin(), card_counts.rend());
        // int left = 1, right = n;
        // int best = 0;

        // // DEBUG(left);
        // // DEBUG(right);

        // while (left <= right) {
        //     int mid = (left + right) / 2;
        //     // DEBUG(mid);
        //     if (check(mid, card_counts, k)) {
        //         best = max(mid, best);
        //         left = mid + 1;
        //     } else {
        //         right = mid - 1;
        //     }
        // }

        // // while (left <= right) {
        // //     int mid = MID(left, right);
        // //     DEBUG(best);
        // //     if (check(mid, card_counts, k)) {
        // //         best = mid;
        // //         left = mid + 1;
        // //     }
        // //     else {
        // //         right = mid - 1;
        // //     }
        // // }

        // cout << best << "\n";
    }
    
    return 0;
}
