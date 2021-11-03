// accepted
// https://codeforces.com/contest/1607/problem/A
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
		string keyboard;
		string word;
		std::cin >> keyboard >> word;

		int count = 0;
		int table[26] = {0};
		for(int i = 0; i < keyboard.size(); i++) {
			table[abs('a' - keyboard[i])] = i;
		}

		for(int i = 1; i < word.size(); i++) {
			count += abs(table[word[i] - 'a'] - table[word[i-1] - 'a']);
		}
		std::cout << count << std::endl;
	}

	return 0; 
}
