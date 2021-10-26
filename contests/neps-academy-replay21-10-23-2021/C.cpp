// https://neps.academy/br/competition/1034
#include <bits/stdc++.h> 
using namespace std; 
#define INF (int)1e9 
#define LONGINF (long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
void initArray(int arr[], int length, int val) { 
	for (int i = 0; i < length; i++) 
		arr[i] = val; 
	return; 
} 

bool isVowel(vector<char>& vowels, char c) {
	for (auto it = vowels.begin(); it != vowels.end(); it++)
		if(c == *it)
			return true;
	
	return false;
}

char getCloserVowel(vector<char>& vowels, char c) {
	int dists[5] = {0};
	int i = 0, dist = INF;
	char closerVowel;
	for (auto it = vowels.begin(); it != vowels.end(); it++) {
		dists[i] = abs(c - *it);
		i++;
	}	
	i = 4;
	for (auto it = vowels.rbegin(); it != vowels.rend(); it++) {
		dist = min(dist, dists[i]);
		if(dist == dists[i])
			closerVowel = *it;
		i--;
	}

	return closerVowel;
}

char getNextConsonant(vector<char>& vowels, char c) {
	if(c == 'z')
		return 'z';
	else if(isVowel(vowels, c+1))
		return c+2;
	else
		return c+1;
}
 
int main() { 
	fastio; 
	// ifstream cin("in.txt"); 
	// ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	string word;
	string translatedWord;
	cin >> word;
	int length = word.size();
	
	vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
	
	for(int i = 0; i < length; i++) {
		
		if(!isVowel(vowels, word[i])) {
			translatedWord += word[i];
			translatedWord += getCloserVowel(vowels, word[i]);
			translatedWord += getNextConsonant(vowels, word[i]);
		}
		else
			translatedWord += word[i];
	} 	
	cout << translatedWord << endl; 
	
	
	return 0; 
}
