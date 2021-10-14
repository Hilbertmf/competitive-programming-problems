// https://neps.academy/br/competition/1019/exercise/1782
#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int n, a, b;
	string str;
	cin >> n >> a >> b;
	cin >> str;

	for (int i = 0; i < a-1; i++)
	{
		printf("%c", str[i]);
	}

	for (int i = b-1; i >= a-1; i--) {
		printf("%c", str[i]);
	}

	for (int i = b; i < n; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
	return 0; 
}