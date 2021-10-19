#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int calcMid(int left, int right) {
    return left + (right - left)/2;
  }
  
  bool isFirstBadVersion(int n) {
    return isBadVersion(n) && !isBadVersion(n-1);
  }
  
  int firstBadVersion(int n) {
  
    int left = 1;
    int right = n;
    
    //edge cases:
    if (isBadVersion(left))
      return left;
    if(isFirstBadVersion(right))
      return right;
    
    int i = calcMid(right, left);
    while(!isFirstBadVersion(i)) {
      if(isBadVersion(i)) 
        right = i;
      else 
        left = i;
      
      i = calcMid(left, right);
    }
    
    return i;
  }
};