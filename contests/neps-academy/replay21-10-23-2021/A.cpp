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
 
void solve() { 
 
} 
 
int solve(int arg) { 
 
} 
 
int main() { 
	fastio; 
	// ifstream cin("in.txt"); 
	// ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	int month, day; 
	cin >> month >> day;

	if(month > 2) {
		cout << "After" << endl;	
	}
	else if(month < 2) {
		cout << "Before" << endl;	
	}
	else if(month == 2) {
		if(day > 18)
			cout << "After" << endl;	
		else if(day < 18)
			cout << "Before" << endl;
		else if(day == 18)
			cout << "Special" << endl;
	}
	
	

	return 0; 
}
