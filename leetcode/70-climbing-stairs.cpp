#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int aux1, aux2, res = 1;
		aux1 = 1;
		aux2 = 1;
		for(int i=2;i <= n; i++)
		{
			res = aux1 + aux2;
			aux1 = aux2;
			aux2 = res;
		}
		return res;
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
		cout << obj.climbStairs(n) << endl;
	}
 
	return 0; 
}