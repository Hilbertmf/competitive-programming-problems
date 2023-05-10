#include <bits/stdc++.h> 
using namespace std; 
// time: O(n*logm)
// space: O(n*m)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> hashmap;
        
        for(string& s : strs) {
            string aux = s;
            sort(aux.begin(), aux.end());
            hashmap[aux].push_back(s);
        }
        
        for(auto& [s, vec] : hashmap) {
            anagrams.push_back(vec);
        }
        return anagrams; 
    }
};