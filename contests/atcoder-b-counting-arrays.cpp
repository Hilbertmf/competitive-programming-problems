// https://atcoder.jp/contests/abc226/tasks/abc226_b
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
	 
	int n;
	std::cin >> n;
	set<vector<int>> sequences;
  
	for(int i = 0; i < n; i++) {
		int length;
		std::cin >> length;
		vector<int> seq;

		for(int j = 0; j < length; j++) {
			int n;
			std::cin >> n;
			seq.push_back(n);
		}
		sequences.insert(seq);		
	}

	std::cout << sequences.size() << std::endl;
	return 0; 
}
