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

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
	unordered_map<int, int> defeats;
	
	for(int i = 0; i < matches.size(); i++) {
		if(defeats.find(matches[i][0]) == defeats.end()) {
			defeats[matches[i][0]] = 0;
		}
		defeats[matches[i][1]]++;
	}

	vector<vector<int>> answer(2);

	for(auto it = defeats.begin(); it != defeats.end(); it++) {
		if(it->second == 0) answer[0].push_back(it->first);
		else if(it->second == 1) answer[1].push_back(it->first);
	}

	sort(answer[0].begin(), answer[0].end());
	sort(answer[1].begin(), answer[1].end());

	return answer;
}

int main() { 
	FASTIO;
	
	
	return 0; 
}
