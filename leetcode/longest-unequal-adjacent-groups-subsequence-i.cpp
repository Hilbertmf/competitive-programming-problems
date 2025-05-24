class Solution {
public:
    void getLongestSubsequenceStartingWith(int start, vector<int>& list, vector<int>& groups) {
        int i;
        for(i = 0; i < groups.size(); ++i) {
            if (groups[i] == start) break;
        }
        
        int cur = groups[i] ^ 1;
        for(i; i < groups.size(); ++i) {
            if (groups[i] != cur) {
                list.push_back(i);
                cur ^= 1;
            }
        }
    }
    
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        vector<int> list1, list2;
        getLongestSubsequenceStartingWith(0, list1, groups);
        getLongestSubsequenceStartingWith(1, list2, groups);
                
        if(list1.size() > list2.size()) {
            for(auto &idx : list1) {
                ans.push_back(words[idx]);
            }
        }
        else {
            for(auto &idx : list2) {
                ans.push_back(words[idx]);
            }            
        }
        return ans;
    }
};