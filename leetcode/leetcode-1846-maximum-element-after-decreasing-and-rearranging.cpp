#include <bits/stdc++.h> 
using namespace std; 

// O(nlogn)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int elem = 0;
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] > elem)
                elem++;
        }
        
        return elem;
    }
};

// O(nlogk) ; k = nº of distinct elems
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        map<int, int> elems_map;
        int elem = 0;
        for(int num : arr) {
            elems_map[num]++;
        }

        for(auto &[num, occ] : elems_map) {
            elem = min(elem + occ, num);
        }

        return elem;
    }
};
