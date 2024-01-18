// https://cses.fi/problemset/task/1070/
// time: O(n)
// space: O(1)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
    FASTIO;

    int n;
    cin >> n;

    if(n <= 3 && n != 1) {
        cout << "NO SOLUTION" << "\n";
    }
    else {

        int mid = n / 2, even_nums;
        if(n % 2 == 0) {
            mid--;
            even_nums = n - 2;
        }
        else {
            even_nums = n - 1;
        }

        for(int i = 0; i < mid; ++i, even_nums -= 2) {
            cout << even_nums << " ";
        }
        cout << n << " ";
        
        int odd_nums = 1;
        for(int i = mid + 1; i < n; ++i, odd_nums += 2) {
            cout << odd_nums << " ";
        }

    }

    return 0;
}

// time: O()
class Solution {
public:
    int climbStairs(int n) {
        int combinations = 0;
        int prev = 0, curr = 1;
        for(int i = 0; i < n; ++i) {
            combinations = prev + curr;
            prev = curr;
            curr = combinations;
        }
        return combinations;
        vector<int> dp(max(n + 1, 3));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};










// https://cses.fi/problemset/task/1070/
// time: O(n)
// space: O(1)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
    FASTIO;

    int n;
    cin >> n;

    if(n <= 3 && n != 1) {
        cout << "NO SOLUTION" << "\n";
    }
    else {

        int mid = n / 2, even_nums;
        if(n % 2 == 0) {
            mid--;
            even_nums = n - 2;
        }
        else {
            even_nums = n - 1;
        }

        for(int i = 0; i < mid; ++i, even_nums -= 2) {
            cout << even_nums << " ";
        }
        cout << n << " ";
        
        int odd_nums = 1;
        for(int i = mid + 1; i < n; ++i, odd_nums += 2) {
            cout << odd_nums << " ";
        }

    }

    return 0;
}










