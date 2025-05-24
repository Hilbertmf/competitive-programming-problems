#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
    FASTIO;
    int t;
    cin >> t;

    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;

        vector<pair<int, int>> intervals(n), h(m);
        for (int i = 0; i < n; ++i) cin >> intervals[i].first >> intervals[i].second;
        for (int i = 0; i < m; ++i) cin >> h[i].first >> h[i].second;

        map<int, int> line;

        // Register interval events (subtract required jumps at the start of each interval)
        for (const auto& [start, end] : intervals) {
            line[start] -= (end - start + 2);
            line[end + 1] += (end - start + 2);
        }

        // Register power-up events (add power-ups at the position of each power-up)
        for (const auto& [pos, value] : h) {
            line[pos] += value;
        }

        int cur_jump = 1, count = 0;
        multiset<int> available_pwr_ups;
        bool ok = true;

        // Process the events sorted by position
        for (const auto& [pos, value] : line) {
            if (pos > l) break;  // Stop if position exceeds L

            if (value > 0) {
                // It's a power-up event, add power-up to the available set
                available_pwr_ups.insert(value);
            } else {
                // It's an interval event, process it
                int required_jump = -value;
                // Use power-ups to fulfill the required jump
                while (cur_jump < required_jump && !available_pwr_ups.empty()) {
                    cur_jump += *available_pwr_ups.rbegin();  // Use the largest available power-up
                    available_pwr_ups.erase(--available_pwr_ups.end());
                    ++count;
                }
                // If we can't fulfill the jump requirement, it's a failure
                if (cur_jump < required_jump) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok)
            cout << count << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}


class Solution {
public:
    int takeCharacters(string s, int k) {
        map<char, vector<int>> mp1, mp2;

        for(int i = 0; i < s.size(); ++i) mp1[s[i]].push_back(i);
        for(int i = s.size() - 1; i >= 0; --i) mp2[s[i]].push_back(i);

        int ans = 0, l = 0, r = s.size() - 1;

        set<char> rem;
        for(auto &[c, v] : mp1) rem.insert(c);
        map<char, int> count;

        while (l <= r && !rem.empty()) {
            int d1 = s.size(), d2 = s.size();
            char c1, c2;
            for(auto &c : rem) {
                if (!mp1[c].empty() && abs(l - mp1[c].back() <= d1)) {
                    c1 = c;
                    d1 = abs(l - mp1[c].back());
                }
                if (!mp2[c].empty() && abs(r - mp2[c].back() <= d2)) {
                    c2 = c;
                    d2 = abs(r - mp2[c].back());
                }
            }
            
            if (!mp1[c1].empty() && d1 < d2) {
                r--;
                ans += d1;
                mp1[c1].pop_back();
                count[c1]++;
                if (count[c1] == k) rem.erase(c1);
            }
            else if (!mp2[c2].empty()) {
                l++;
                ans += d2;
                mp2[c2].pop_back();
                count[c2]++;
                if (count[c2] == k) rem.erase(c2);
            }
            else break;
        }

        return ans;
    }
};
