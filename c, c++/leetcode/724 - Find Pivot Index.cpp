#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;

// Find pivot index or equilibrium index of an array
// using prefix sum algorithm

int pivotIndex(vector<int>& nums)
{
  int length = nums.size();

  if(length == 1) return 0;
  if(length == 2) return -1;

  int prefix_sum[10010] = {0};
  prefix_sum[0] = nums[0];
  int left_sum = 0, right_sum = 0;
  for(int i=1;i<length;i++)
    prefix_sum[i] += nums[i] + prefix_sum[i-1];
  
  for(int i=0;i<length;i++)
  {
    left_sum = (i > 0) ? prefix_sum[i-1] : 0;
    right_sum = (i < length-1) ? prefix_sum[length-1] - prefix_sum[i] : 0;
    
    if(left_sum == right_sum) return i;
  }
  return -1;
}
int main() {
	// your code goes here
	long long n;
	cin >> n;
	vector<int> nums;
  int aux;
	for(long long i=0;i<n;i++)
  {
    cin >> aux;
    nums.push_back(aux);
  }
		
	
	cout << pivotIndex(nums) << endl;
	return 0;
}