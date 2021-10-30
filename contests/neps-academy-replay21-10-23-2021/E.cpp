// contest: https://neps.academy/br/competition/1034
// problem link: https://neps.academy/br/exercise/1825
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
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
	fastio; 
	// ifstream cin("in.txt"); 
	// ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	int slices, numPeople; 
	cin >> slices >> numPeople; 
	int people[slices] = {0}; 

	// start w/ all 1s and last element has rest of slices
	for(int i = 0; i < numPeople-1; i++) { 
		people[i] = 1;
	} 
	people[numPeople - 1] = slices - (numPeople - 1);

	int count = 1;

	for(int i = 0; i < numPeople; i++) { 
		DEBUG(people[i]);
	} 

	cout << numPeople << endl; 
	//printf("%d", numPeople); 
	return 0; 
}
