#include <bits/stdc++.h> 
#include <algorithm>
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
	for(int test = 0; test < t; test++) {
		vector<int> cyan(3);
		vector<int> magenta(3);
		vector<int> yellow(3);
		vector<int> black(3);
		int units = 0;
		for(int i = 0; i < 3; i++) {
			std::cin >> cyan[i] >> magenta[i] >> yellow[i] >> black[i];
		}
		int minCyan = *min_element(cyan.begin(), cyan.end());
		int minMagenta = *min_element(magenta.begin(), magenta.end());
		int minYellow = *min_element(yellow.begin(), yellow.end());
		int minBlack = *min_element(black.begin(), black.end());;
		units = minCyan + minMagenta + minYellow + minBlack;
		
		cout << "Case #" << test+1 << ": ";
		if(units < 1000000) std::cout << "IMPOSSIBLE" << std::endl;
		else {
			int diff = units - 1000000;
			map<string, int> colors;
			colors.insert(make_pair(string("cyan"), minCyan));
			colors.insert(make_pair(string("magenta"), minMagenta));
			colors.insert(make_pair(string("yellow"), minYellow));
			colors.insert(make_pair(string("black"), minBlack));
			for(auto it = colors.begin(); it != colors.end() && diff > 0; it++) {
				if(diff > it->second)	{
					diff -= it->second;
					it->second = 0;
				}
				else {
					it->second -= diff;
					diff = 0;
				}
			}
			
			std::cout << colors["cyan"] << " " << colors["magenta"] << " " << colors["yellow"] << " " << colors["black"] << std::endl;
		}
	}
	
	return 0; 
}
