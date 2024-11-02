#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int32_t main() {
    FASTIO;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        map<int, int> freq;
        for (int num : a) freq[num]++;

        priority_queue<pair<int, int>> maxHeap;
        for (const auto& [num, frequency] : freq) {
            maxHeap.push({frequency, num});
        }

        vector<int> idealArr;
        while (!maxHeap.empty()) {
            auto [frequency, num] = maxHeap.top();
            maxHeap.pop();
            for (int i = 0; i < frequency; ++i) {
                idealArr.push_back(num);
            }
        }

        vector<int> rearrangedArr(n);
        int left = 0, right = 0;

        for (int i = 0; i < idealArr.size(); ++i) {
            if (i % 2 == 0) {
                rearrangedArr[left++] = idealArr[i];
            } else {
                rearrangedArr[n - 1 - right++] = idealArr[i];
            }
        }

        int dist = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) dist++;
        }

        int l = 0, r = n - 1;

        while (l < r) {
            if (a[l] != rearrangedArr[l]) {
                int cur_dist = dist;
                if (l > 0 && a[l] == a[l - 1]) cur_dist--;
                if (l < n - 1 && a[l] == a[l + 1]) cur_dist--;
                if (r > 0 && a[r] == a[r - 1]) cur_dist--;
                if (r < n - 1 && a[r] == a[r + 1]) cur_dist--;

                swap(a[l], a[r]);

                if (l > 0 && a[l] == a[l - 1]) cur_dist++;
                if (l < n - 1 && a[l] == a[l + 1]) cur_dist++;
                if (r > 0 && a[r] == a[r - 1]) cur_dist++;
                if (r < n - 1 && a[r] == a[r + 1]) cur_dist++;

                if (cur_dist < dist) {
                    dist = cur_dist;
                } else {
                    swap(a[l], a[r]);
                }
            }
            l++;
            r--;
        }
        
        

        cout << dist << "\n";
    }

    return 0;
}
