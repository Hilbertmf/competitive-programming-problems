class Solution {
public:
  bool isPeak(vector<int>& nums, int pos) {
    // edge cases:
    if (pos < 1) {
      // compare w/ pos+1
      if (nums[pos] > nums[pos+1])
        return true;
      else
        return false;
    }
    else if (pos > nums.size() - 2) {
      // compare w/ pos - 1
      if (nums[pos] > nums[pos-1])
        return true;
      else
        return false;
    }
    else {
      if (nums[pos] > nums[pos-1] && nums[pos] > nums[pos+1])
        return true;
      else
        return false;
    }
  }
  
  int calcMid(int left, int right) {
    return left + (right - left)/2;
  }
  
  int findPeakElement(vector<int>& nums) {
    
    int peakIdx = -1;
    int length = nums.size();
    int left = 0, right = length - 1;
    int currIdx = calcMid(left, right);
    
    // edge cases
    if (length == 1)
      return 0;
    if (isPeak(nums, 0)) 
      return 0;
    if (isPeak(nums, length - 1))
      return length - 1;
    
    while(!isPeak(nums, currIdx)) {
      
      if (nums[currIdx] < nums[currIdx+1])
        left = currIdx;
      else
        right = currIdx;
      
      currIdx = calcMid(left, right);
    }
    
    peakIdx = currIdx;
    return peakIdx;
  }
};