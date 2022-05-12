// https://neps.academy/br/competition/1019/exercise/1779
#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
bool isVowel(char c) {
	char vowels[] = {'a', 'e', 'i', 'o', 'u'};
	for(int i=0; i<5;i++) {
		if(c == vowels[i]) {
			return true;
		}
			
	}
	return false;
}

int main()
{ 
	int length;
	string str;
	int numVowels = 0;
	cin >> length >> str;

	for(int i=0; i<length;i++) {
		if(isVowel(str[i]))
			numVowels++;
	}
 
	printf("%d\n", numVowels);
 
	return 0; 
}
