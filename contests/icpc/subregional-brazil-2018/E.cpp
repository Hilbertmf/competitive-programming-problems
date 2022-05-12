#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
void initArray(int arr[], int length, int val) { 
	for (int i = 0; i < length; i++) 
		arr[i] = val; 
	return; 
} 
 
void solve() { 
 
} 
 
int solve(int arg) { 
 
} 
 
int main() { 
	FASTIO; 
	//ifstream cin("in.txt"); 
	//ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	string msg, crib; 
	cin >> msg >> crib;
	int cribSize = crib.size();
	int slides = msg.size() - cribSize + 1;

	int numPos = 0;
	for(int i = 0; i < slides; i++) { 
		bool isPossible = true;
		for (int j = 0, msgIdx = i; j < cribSize; j++, msgIdx++) {
			if(msg[msgIdx] == crib[j]) {
				isPossible = false;
				break;
			}
		}
		if(isPossible)
			numPos++;
	} 

	cout << numPos << endl;  
	return 0; 
}
