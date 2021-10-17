#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int guests[5] = {0};
	for (int i = 0; i < 5; i++)
	{
		cin >> guests[i];
	}

	int ans = 0;
	ans += guests[0] * 300;
	ans += guests[1] * 1500;
	ans += guests[2] * 600;
	ans += guests[3] * 1000;
	ans += guests[4] * 150;
	ans += 225;
 
	printf("%d\n", ans);
 
	return 0; 
}
