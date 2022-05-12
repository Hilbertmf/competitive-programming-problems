#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int birdWt, foodWt, noLeaves;
	int leaves[110] = {0};
 
	scanf("%d %d %d", &birdWt, &foodWt, &noLeaves);
	for (int i = 0; i < noLeaves; i++)
	{
		cin >> leaves[i];
	}
	int foodInLeaves[noLeaves] = {0};
	int currWt = birdWt + foodWt;//leaves[0];
	int noLeavesWithFood = 0;

	for (int i = 0; i < noLeaves-1 && currWt >= birdWt; i++)
	{
		if(i == 0) {
			currWt = leaves[i];
			if(currWt <= birdWt)
				break;
		}
		if (leaves[i+1] < currWt) {
			foodInLeaves[i] = min(currWt - leaves[i+1], currWt - birdWt);
			currWt = leaves[i+1];
		}	
	}

	for (int i = 0; i < noLeaves; i++)
	{
		if(foodInLeaves[i])
			noLeavesWithFood++;
	}

	printf("%d\n", noLeavesWithFood);

	// int leavesWithFood[noLeaves] = {0};
	
	
	
	// if(leaves[0] > birdWt && noLeaves == 1) {
	// 	leavesWithFood[0]++;
	// }
	// currWt = leaves[0];
	// int i;
	// for (i = 1; i < noLeaves && leaves[i] >= birdWt; i++)
	// {
	// 	if(leaves[i] < currWt && leaves[i] >= birdWt) {
	// 		leavesWithFood[i-1]++;
	// 		currWt = leaves[i];
	// 	}
	// }

	// // printf("i = %d\n", i);
	// // if (i != noLeaves && leaves[i-1] > birdWt) {
	// 	// cout << "test";
	// 	// leavesWithFood[i]++;
	// // }
	
	// for (int i = 0; i < noLeaves; i++)
	// {
	// 	if(leavesWithFood[i])
	// 		noLeavesWithFood++;
	// }
 
	// printf("%d\n", noLeavesWithFood);

 
	return 0; 
}
