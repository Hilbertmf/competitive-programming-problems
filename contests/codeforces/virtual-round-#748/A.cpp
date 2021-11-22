// https://codeforces.com/contest/1593/problem/A
// accepted
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

long long getWinner(long long a, long long b, long long c) {
		return max(max(a, b), c);
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;

	while (t--) {
		long long candidates[3];
		bool tiesForWinner = false;
		std::cin >> candidates[0] >> candidates[1] >> candidates[2];
		int winner = getWinner(candidates[0], candidates[1], candidates[2]);
		if((candidates[0] == winner && candidates[1] == winner) ||
		 (candidates[1] == winner && candidates[2] == winner) ||
		 (candidates[0] == winner && candidates[2] == winner))
			tiesForWinner = true;
		vector<long long> solution;

		for(int i = 0; i < 3; i++) {
			int sol = (candidates[i] == winner) ? 0 : abs(winner - candidates[i])+1;
			if(tiesForWinner && candidates[i] == winner) sol++;
			solution.push_back(sol);
		}
		std::cout << solution[0] << " " << solution[1] << " " << solution[2] << std::endl;
	}
	
	return 0; 
}
