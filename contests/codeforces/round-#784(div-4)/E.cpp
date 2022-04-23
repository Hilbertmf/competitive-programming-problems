// wa
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
	int t;
	std::cin >> t;
	while (t--) {
		int numStrings;
		std::cin >> numStrings;
		vector<string> strings(numStrings);
		for(int i = 0; i < numStrings; i++) {
			std::cin >> strings[i];
		}
		multimap<pair<string, string>, int> matchPairs;
		// unordered_map <pair<string, string>, int> matchPairs;
		for(auto &str : strings) {
			for(int i = 0; i < numStrings; i++) {
				if(str != strings[i]) {
					if( (str[0] == strings[i][0] && str[1] != strings[i][1]) || 
							str[1] == strings[i][1] && str[0] != strings[i][0]) {
								
								pair<string, string> p = make_pair(str, strings[i]);
								pair<string, string> reversePair = make_pair(strings[i], str);
								
								if(matchPairs.find(p) == matchPairs.end() && matchPairs.find(reversePair) == matchPairs.end() ) {
									matchPairs.insert(make_pair(p, 1));
								}
							}


				}
			}

			
		}
		std::cout << matchPairs.size() << std::endl;

	}
	
	return 0; 
}
