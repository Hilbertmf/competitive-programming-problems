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
	// freopen("out.txt","w",stdout); // use this one for printf to file 

	int noPlates, noRounds, ans; 
	cin >> noRounds >> noPlates;
	int totalPlates = noPlates * noRounds;
	int milestones[9] = {0};
	double percentages[9] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
	for(int i = 0; i < 9; i++) {
		milestones[i] = ceil(totalPlates*percentages[i]);
	}
	for(int i = 0; i < 9; i++) {
		if(i > 0)
			cout << " ";
		cout << milestones[i];
	}

	cout << endl; 
	//printf("%d", ans); 
	return 0; 
}
