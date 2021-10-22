#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
class Solution {
public:
    
// if the array can be partioned into two subsets such
// that the sum is equal, then:
// sum(arr) % 2 == 0
// and sum(set1) == sum(set2) == sum(arr)/2
  
// if array length = 1, then its false
//  
// we can model the problem as if its a knapsack with capacity = sum(set1)
// values[i] = weights[i] = arr[i]
// then we can try to fill the knapsack until totalSum / 2
// if dp[noItems][totalSum/2] == totalSum / 2 then return true
  
  
  int calcSum(vector<int>& nums) {
    int acc = 0;
    for(auto i = nums.begin(); i != nums.end(); i++)
      acc += *i;
    
    return acc;
  }
  
  bool canPartition(vector<int> &nums) {
    int noItems = nums.size();
    int sum = calcSum(nums);
    int dp[noItems+1][sum+1];

    // edge cases
    if(sum %2 != 0 || noItems < 2)
      return false;

    for(int i = 0; i <= noItems; i++) {
      for(int s = 0; s <= sum/2; s++) {
        if(i == 0 || s == 0)
          dp[i][s] = 0;
        else if(s < nums[i-1])
          dp[i][s] = dp[i-1][s];
        else {
          int include = nums[i-1] + dp[i-1][s - nums[i-1]];
          int exclude = dp[i-1][s];
          dp[i][s] = max(include, exclude);
        }
      }
    }

    return dp[noItems][sum/2] == sum/2;
  }
};