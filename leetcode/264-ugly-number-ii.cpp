#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
#define INFINITE 0x3f3f3f3f
class Solution {
public:
    int nthUglyNumber(int n) {
        int idx2 = 0; // power of 0
        int idx3 = 0;
        int idx5 = 0;
        vector<int> uglyNums(n+1);
        uglyNums[0] = 1;

        for(int i = 1; i <= n; ++i) {
            int num2 = uglyNums[idx2]*2;
            int num3 = uglyNums[idx3]*3;
            int num5 = uglyNums[idx5]*5;

            uglyNums[i] = min(num2, min(num3, num5));
            if(uglyNums[i] == num2) {
                idx2++;
            }
            if(uglyNums[i] == num3) {
                idx3++;
            }
			if(uglyNums[i] == num5) {
                idx5++;
            }
        }

        return uglyNums[n];
    }
};

int main() 
{ 
	int cases;
	cin >> cases;
	while (cases--)
	{
		int n;
		cin >> n;
		Solution obj;
		cout << obj.nthUglyNumber(n) << endl;
	}
 
	return 0; 
}
