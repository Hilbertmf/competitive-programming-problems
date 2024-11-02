#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

int32_t main() {
    FASTIO;
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int ans = 0;
        map<int, int> freq;
        int left = 0;

        for(int right = 0; right < n; ++right) {
            if (right > 0 && a[right] - a[right - 1] > 1) {
                left = right;
                freq.clear();
            }
            
            freq[a[right]]++;

            while (freq.size() > k) {
                freq[a[left]]--;
                if (freq[a[left]] == 0) {
                    freq.erase(a[left]);
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        cout << ans << "\n";
    }

    return 0;
}
