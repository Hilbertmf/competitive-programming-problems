// accepted
// https://neps.academy/br/competition/1199/exercise/2007
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
 
int main() { 
	FASTIO;
	int n;
	string s;
	std::cin >> n >> s;
	unordered_map<char, int> chars;
	for(auto &c : s) {
		chars[c]++;
	}
	bool flag = false;
	int count = 0;
	for(auto &kvp : chars) {
		count++;
		if(count >= 3) {
			std::cout << "Yes" << std::endl;
			flag = true;
			break;
		}
	}
	if(!flag) std::cout << "No" << std::endl;
	
	return 0; 
}
