// accepted
// https://codeforces.com/contest/1605/problem/B
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

	int t;
	std::cin >> t;
	while (t--) {
		int length;
		string str;
		std::cin >> length;
		std::cin >> str;
		string sortedStr = str;
		sort(sortedStr.begin(), sortedStr.end());
		// it's either 0 or 1 operation
		if(str == sortedStr)
			std::cout << 0 << std::endl;
		else {
			vector<int> indices;
			for(int i = 0; i < str.size(); i++) {
				if(str[i] != sortedStr[i])
					indices.push_back(i+1);
			}
			std::cout << 1 << std::endl;
			std::cout << indices.size();

			for(auto it = indices.begin(); it != indices.end(); it++)
				std::cout << " " << *it;

			std::cout << std::endl;
		}
	}
	return 0; 
}
