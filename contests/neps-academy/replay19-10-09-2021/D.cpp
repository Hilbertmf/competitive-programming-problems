// https://neps.academy/br/competition/1019/exercise/1781
#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int notas[3] = {0};

	for(int i=0; i<3;i++)
		cin >> notas[i];

	sort(notas, notas+3, greater<int>());

	printf("%d\n", notas[0]+notas[1]);
 
	return 0; 
}
