// https://neps.academy/br/competition/1019/exercise/1778
#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int arr[3], moreFrequent;
	int map[3] = {0};
	
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
 
	for(int i=0; i<3;i++)
		map[arr[i]]++;

	if(map[1] > map[2])
		moreFrequent = 1;
	else
		moreFrequent = 2;
	printf("%d", moreFrequent);
 
	return 0; 
}
