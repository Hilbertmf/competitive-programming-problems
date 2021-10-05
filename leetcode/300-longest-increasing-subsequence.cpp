#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int size = nums.size();
		
		// array to store lenghts of subsequences
		int lengths[size+10];
		int i = 1, j = 0, maxValue = 0;
		
		// set all values to 1
		for(i = 0; i < size+10; i++)
			lengths[i] = 1;

		for(i = 1; i < size; i++) {
			maxValue = 0;
			for(j = 0; j < i; j++) {
				if(nums[j] < nums[i])
					maxValue = max(maxValue, lengths[j]);
			}
			lengths[i] = 1 + maxValue;
		}
		
		sort(lengths, lengths + size, greater<int>());
		// return the larger subsequence length
		return lengths[0];
	}
};

int main() 
{ 
	int cases;
	cin >> cases;
	while (cases--)
	{
		int length;
		int num;
		vector<int> nums;

		cin >> length;
		for(int i = 0;i < length; i++) {
			cin >> num;
			nums.push_back(num);
		}
		Solution obj;
		cout << obj.lengthOfLIS(nums) << endl;
	}
 
	return 0; 
}