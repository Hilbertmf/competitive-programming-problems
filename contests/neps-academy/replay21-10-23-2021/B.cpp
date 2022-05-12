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
 
int main() { 
	fastio; 
	// ifstream cin("in.txt"); 
	// ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	string txt;
	getline(cin, txt);
	string happyFace = ":-)";
	string sadFace = ":-(";
	int happyEmojis = 0;
	int sadEmojis = 0;
	int length = txt.size();

	for (int i = 0; i < length-3; i++) {
		if(txt[i] == ':' && txt[i+1] == '-') {
			if(txt[i+2] == ')')
				happyEmojis++;
			else if(txt[i+2] == '(')
				sadEmojis++;		
		}
	}
	
	if(happyEmojis == 0 && sadEmojis == 0)
		cout << "none" << endl;
	else if(happyEmojis == sadEmojis)
		cout << "unsure" << endl;
	else if(happyEmojis > sadEmojis)
		cout << "happy" << endl;
	else if(happyEmojis < sadEmojis)
		cout << "sad" << endl;
	
	return 0; 
}
