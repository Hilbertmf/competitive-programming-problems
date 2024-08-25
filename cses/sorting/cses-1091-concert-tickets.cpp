// https://cses.fi/problemset/task/1091/
// time: O(nlogn)
// space: O(n)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int main() {
    FASTIO;
 
    int num_tickets, num_people, ticket;
    cin >> num_tickets >> num_people;
    multiset<int> prices;
    vector<int> people(num_people);
    for(int i = 0; i < num_tickets; ++i) {
        cin >> ticket;
        prices.insert(ticket);
    }
    for(auto &person : people) cin >> person;
 
    for(int i = 0; i < num_people; ++i) {
 
        auto it = prices.lower_bound(people[i]);
        if(prices.empty() ||
        (it != prices.end() && *it > people[i] && it == prices.begin())) {
            cout << "-1\n";
            continue;
        }
        else if(it == prices.end() || *it > people[i]) {
            --it;
        }
        
        cout << *it << "\n";
        prices.erase(it);
 
    }
    
 
    return 0;
}



/*

f(i, j) = lcs at i in text1 and j in text2

include: 
    if text1[i] == text2[j]:
        1 + f(i-1, j-1)
exc:
    max(f(i-1, j), f(i, j-1))

    else: 0
exclude: f(i - 1, j - 1)

[o..i]
[o..j]

exclude: 

  v
ebfcfda
abzczde


r: 1
r: 1
  v
ace

1
2

*/





// time: O(n²)
// space: O(n²)
class Solution {
public:
    int f(int i, int j, string& text1, string& text2,
    vector<vector<int>>& dp) {
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == 0 && j == 0) {
            if(text1[i] == text2[j])
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }

        else if(i == 0) {
            if(text2.substr(0, j + 1).find(text1[i]) != string::npos)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }

        else if(j == 0) {
            if(text1.substr(0, i + 1).find(text2[j]) != string::npos)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }

        else {

            int include = 0;
            if(text1[i] == text2[j])
                include = 1 + f(i - 1, j - 1, text1, text2, dp);

            int exclude = max(f(i - 1, j, text1, text2, dp),
                            f(i, j - 1, text1, text2, dp));
            
            dp[i][j] = max(include, exclude);
        }
        
        return dp[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, text1, text2, dp);
    }
};















class Solution {
public:
    bool isBoundary(int row, int col, int rows, int cols) {
        return row == 0 || row == rows - 1 || col == 0 || col == cols - 1;
    }

    bool isCorner(int row, int col, int rows, int cols) {
        return (row == 0 && col == 0) || (row == 0 && col == cols - 1) ||
               (row == rows - 1 && col == cols - 1) || (row == rows - 1 && col == 0);
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        


    }
};
