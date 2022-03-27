class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
		vector<int> diff1;
		vector<int> diff2;
		for(auto it = set1.begin(); it != set1.end(); it++) {
      if(set2.find(*it) == set2.end()) {// !contains
				diff1.push_back(*it);
			}
		}	
		for(auto it = set2.begin(); it != set2.end(); it++) {
			if(set1.find(*it) == set1.end()) { // !contains
				diff2.push_back(*it);
			}
		}

		vector<vector<int>> ans;
		ans.push_back(diff1);
		ans.push_back(diff2);
		return ans;
	}
};