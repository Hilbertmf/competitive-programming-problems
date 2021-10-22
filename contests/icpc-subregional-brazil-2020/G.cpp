#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int noBoxes;
	int credits = 100;
	scanf("%d", &noBoxes);
	int boxes[noBoxes+1] = {0};
	for (int i = 0; i < noBoxes; i++)
	{
		cin >> boxes[i];
	}
	
	int ans = 100;

	for (int i = 0; i < noBoxes; i++)
	{
		credits += boxes[i];
		ans = max(ans, credits);
	}


	printf("%d\n", ans);
 
	return 0; 
}
