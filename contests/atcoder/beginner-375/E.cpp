#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

const int MAX_N = 101;
const int MAX_B = 1501;
const int SHIFT = MAX_N * MAX_B;  // Maximum possible difference in strength
const int INF = numeric_limits<int>::max() / 2;  // Large value for "infinity"

int dp[2 * SHIFT + 1];  // 1D DP array for difference tracking

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> people;  // (team, strength)
    int total_strength = 0;

    for (int i = 0; i < n; i++) {
        int team, strength;
        cin >> team >> strength;
        people.push_back({team, strength});
        total_strength += strength;
    }

    // Initialize dp array
    fill(dp, dp + 2 * SHIFT + 1, INF);
    dp[SHIFT] = 0;  // Base case: difference is 0 at the start (balanced teams)

    for (auto person : people) {
        int team = person.first;
        int strength = person.second;

        // Make a copy of the current dp array to avoid overwriting states
        int new_dp[2 * SHIFT + 1];
        copy(dp, dp + 2 * SHIFT + 1, new_dp);

        // Transition this person to different teams
        for (int diff = 0; diff <= 2 * SHIFT; diff++) {
            if (dp[diff] == INF) continue;

            // Keep the person in their current team
            new_dp[diff] = min(new_dp[diff], dp[diff]);

            // Try moving the person to different teams
            if (team != 1 && diff + strength <= 2 * SHIFT) {  // Move to team 1
                new_dp[diff + strength] = min(new_dp[diff + strength], dp[diff] + 1);
            }
            if (team != 2 && diff - strength >= 0) {  // Move to team 2
                new_dp[diff - strength] = min(new_dp[diff - strength], dp[diff] + 1);
            }
        }

        // Update dp with the new transitions
        copy(new_dp, new_dp + 2 * SHIFT + 1, dp);
    }

    // Find the minimum number of switches needed to balance the teams
    if (dp[SHIFT] == INF) {
        cout << -1 << endl;  // Not possible to balance the teams
    } else {
        cout << dp[SHIFT] << endl;  // Minimum number of switches
    }

    return 0;
}
