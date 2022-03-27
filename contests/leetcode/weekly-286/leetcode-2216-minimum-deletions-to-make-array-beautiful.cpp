class Solution {
public:
  int minDeletion(vector<int>& nums) {
    int numDeletions = 0;
    for(int i = 0; i < nums.size() - 1; i++) {
      if((i + numDeletions) % 2 == 0 && nums[i] == nums[i+1]) {
        numDeletions++;
      }
    }
    
    if((nums.size() - numDeletions) % 2 != 0)
      numDeletions++;
    return numDeletions;
  }
};