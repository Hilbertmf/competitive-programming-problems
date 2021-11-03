// accepted
// https://codeforces.com/contest/1607/problem/D
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
 
int main() { 
	FASTIO; 
	//ifstream cin("in.txt"); 
	//ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	//long long t, ans; 
	int t, ans; 
	cin >> t; 
	while (t--) {
		int length;
		std::cin >> length;
		int arr[200010];
		string colors;
		int sum = 0;
		int rsum = 0;
		for(int i = 0; i < length; i++) {
			std::cin >> arr[i];
			sum += arr[i];
			rsum += i;
		}

		std::cin >> colors;
		vector<int> blues;
		vector<int> reds;

		for(int i = 0; i < colors.size(); i++) {
			if(colors[i] == 'B')
				blues.push_back(arr[i]);
			else
				reds.push_back(arr[i]);
		}
		
		bool isPossible = true;
		sort(blues.begin(), blues.end());
		sort(reds.begin(), reds.end());

		int count = 1;
		// loop over blues and reds
		for(auto it = blues.begin(); it != blues.end(); it++, count++) {
			if(*it < count) {
				isPossible = false;
			}
		}
		for(auto it = reds.begin(); it != reds.end() && isPossible; it++, count++) {
			if(*it > count) {
				isPossible = false;
			}
		}

		if(isPossible) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
	
	return 0; 
}
