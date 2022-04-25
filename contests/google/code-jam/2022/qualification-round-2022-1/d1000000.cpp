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
	for(int test = 0; test < t; test++) {
		int numDice;
		std::cin >> numDice;

		vector<int> dice(numDice);
		for(int i = 0; i < numDice; i++) {
			std::cin >> dice[i];
		}

		sort(dice.begin(), dice.end());

		int straightIdx = 1;
		int discardedDice = 0;
		for(int i = 0; i < numDice; i++) {
			// DEBUG(straightIdx);
			// DEBUG(i);
			// DEBUG(dice[i]);
			if(dice[i] < straightIdx) { // discard
				while(i < numDice && dice[i] < straightIdx) {
					i++;
					discardedDice++;
				}
			}
			if(dice[i] >= straightIdx) straightIdx++;
		}
		// DEBUG(straightIdx);
		// DEBUG(discardedDice);
		cout << "Case #" << test+1 << ": " << numDice - discardedDice << endl;
	}
	
	return 0; 
}
