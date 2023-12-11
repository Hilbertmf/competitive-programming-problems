#include <bits/stdc++.h>
using namespace std;

int main() {

    string in;
    int ans = 0;

    while (getline(cin, in)) {
        
        vector<int> nums;
        stringstream ss(in);
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }

        // for part2 uncomment this line
        // reverse(nums.begin(), nums.end());

        int i = nums.size() - 1;
        
        vector<int> sol;
        sol.push_back(nums.back());
        while (nums.size() > 0) {
            for(int i = 0; i < nums.size() - 1; ++i) {
                nums[i] = nums[i + 1] - nums[i];
            }
            nums.resize(nums.size() - 1);
            sol.push_back(nums.back());

            bool all_zero = true;

            for(auto &n : nums) {
                if(n != 0) {
                    all_zero = false;
                    break;
                }
            }

            if(all_zero) break;

        }

        ans += accumulate(sol.begin(), sol.end(), 0);

    }

    cout << ans << "\n";

    return 0;
}