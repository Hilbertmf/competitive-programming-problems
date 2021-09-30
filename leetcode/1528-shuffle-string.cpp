#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;

class Solution {
public:
	string restoreString(string str, vector<int>& indices) {
		string result = str;
		int length = str.length();
		for(int i=0;i<length;i++)
		{
			result[indices[i]] = str[i];
		}
		return result;
	}
};
