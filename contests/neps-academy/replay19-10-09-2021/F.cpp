// https://neps.academy/br/competition/1019/exercise/1784
#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int n, range, maxValue;
	int arrA[110];
	int arrB[110] = {0};
	scanf("%d %d", &n, &range);
	for (int i = 0; i < n; i++)
	{
		cin >> arrA[i];
	}

	for (int i = 0; i < n; i++) {
		arrB[arrA[i]]++;
	}

	sort(arrB, arrB+110, greater<int>());
	
	printf("%d\n", arrB[0]);
 
	return 0; 
}
