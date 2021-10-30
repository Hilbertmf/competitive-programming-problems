// TODO problem
#include <bits/stdc++.h> 
using namespace std; 
#define INF (int)1e9 
#define LONGINF (long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define fastio ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0); 
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

	int amount, noCoins; 
	cin >> amount >> noCoins; 
	int coins[1010] = {0}; 
	bool isPossible = true;
	
	for(int i = 0; i < noCoins; i++) { 
		cin >> coins[i]; 
	}
	// cout << "log1" << endl;
	vector<vector<int>> dp(1001, vector<int> (100001,0));
	

	for (int i = 0; i <= noCoins; i++) {
		for(int j = 0; j <= amount; j++) { 
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(j >= coins[i-1]) {
				int include = coins[i-1] + dp[i-1][j - coins[i-1]];
				int exclude = dp[i-1][j];
				dp[i][j] = max(include, exclude);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	if(dp[noCoins][amount] != amount)
		isPossible = false;

	if(isPossible)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	return 0; 
}
