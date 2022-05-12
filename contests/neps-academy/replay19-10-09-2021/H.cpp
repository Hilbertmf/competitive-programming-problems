// https://neps.academy/br/competition/1019/exercise/1786
#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int length;
	string str;
 
	cin >> length >> str;

	for (int i = 0; i < length; i++)
	{
		if(str[i] == 'j' && i < length - 2) {
			if (str[i+1] == 'o' && str[i+2] == 'i') {
				printf("JOI");
				i += 2;
			}
			else
				printf("%c",str[i]);
		}
		else
			printf("%c",str[i]);
	}
	
 
	printf("\n");
 
	return 0; 
}
