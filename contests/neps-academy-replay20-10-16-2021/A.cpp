#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int numProblems;
	
	cin >> numProblems;
	string wrongAnswers;
	cin >> wrongAnswers;
	
	int classSize;
	cin >> classSize;
	string classAnswers[classSize];// same as grid[numP][ClassS]
	for (int i = 0; i < classSize; i++)
	{
		cin >> classAnswers[i];
	}

	int mapAnswers[26] = {0};
	int count = 0;
	for (int i = 0; i < numProblems; i++)
	{
		memset(mapAnswers, 0, sizeof(mapAnswers));
		for (int j = 0; j < classSize; j++)
		{
			if (classAnswers[j][i] != wrongAnswers[i]) // grid[0][0]; grid[0][1]; grid[0][2]
			{
				mapAnswers[classAnswers[j][i]-'A']++;
			}
		}
		
		sort(mapAnswers, mapAnswers+26, greater<int>());
		count += mapAnswers[0];
	}
	
	
	printf("%d\n", count);
 
	return 0; 
}
