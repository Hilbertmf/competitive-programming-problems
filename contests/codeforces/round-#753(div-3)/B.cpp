// accepted
// https://codeforces.com/contest/1607/problem/B
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

	int t, ans; 
	cin >> t;

	while(t--) {
		long long pos, jumps;
		std::cin >> pos >> jumps;
		long long mods[4] = {0, jumps, -1, -1*(jumps+1)};

		// if pos even reduce, else increment by one of 4 values
		pos += pow(-1, (pos%2) + 1) * mods[jumps % 4];

		std::cout << pos << std::endl;
	}
	
	return 0; 
}
