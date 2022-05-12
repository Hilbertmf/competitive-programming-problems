// https://neps.academy/br/competition/1019/exercise/1787
#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int n;
	int arr[110];
	int sequenceLength = 1;
	int maxLength = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 1; i < n; i++)
	{
		if(arr[i-1] <= arr[i]) {
			sequenceLength++;
			maxLength = max(sequenceLength, maxLength);
		}
		else {
			sequenceLength = 1;
			maxLength = max(sequenceLength, maxLength);
		}
	}
	
	printf("%d\n", maxLength);
 
	return 0; 
}
