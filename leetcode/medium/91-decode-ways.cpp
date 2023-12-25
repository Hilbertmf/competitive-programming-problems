// https://leetcode.com/problems/decode-ways/
class Solution {
public:
    // time: O(n)
    // space: O(n)
    int numDecodings(string s) {  
        
        vector<bool> vis(s.size() + 1);
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0') {
                if(i == 0 ||
                (i > 0 && (s[i - 1] == '0' || s[i - 1] >= '3'))) {
                    return 0;
                }
                
                vis[i] = true;
                vis[i + 1] = true;
            }
        }

        vector<int> dp(s.size() + 1);
        dp[0] = 1;

        for(int i = 1; i <= s.size(); ++i) {
            // finds 10/20: only one possibility
            if(vis[i]) {
                dp[i] = dp[i - 1];
                continue;
            }
            // consider digit used as unit
            dp[i] += dp[i - 1];

            if(i < s.size()) {
                string pair;
                pair += s[i - 1];
                pair += s[i];

                // consider forming a pair w/ next digit
                if(pair[0] == '1' ||
                (pair[0] == '2' && pair[1] <= '6')) {
                    dp[i + 1] += dp[i - 1];
                }
            }
        }

        return dp[s.size()];
    }
};