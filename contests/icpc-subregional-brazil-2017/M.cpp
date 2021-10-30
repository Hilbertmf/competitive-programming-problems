#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9
#define LONGINF (long long)1e18 
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

	// long long a1, a2, a3, ans; 

	int a1, a2, a3, ans = INF;
	cin >> a1 >> a2 >> a3;
	int values[3] = {0}; 
	//long long objs[a1, a2, a3] = {0}; 


	values[0] = a2*2 + a3*4;
	values[1] = a1*2 + a3*2;
	values[2] = a2*2 + a1*4;
	
	for(int i = 0; i < 3; i++) { 
		ans = min(ans, values[i]);
	}
	cout << ans << endl;
	
	

	// cout << ans << endl; 
	//printf("%d", ans); 
	return 0; 
}
