// https://codeforces.com/contest/1593/problem/C
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
 
int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		long long holePos, numMice;
		std::cin >> holePos >> numMice;
		vector<long long> mices(numMice);
		for(int i = 0; i < numMice; i++) 
			std::cin >> mices[i];
		

		sort(mices.begin(), mices.end(), greater<int>());

		long long catPos = 0;
		long long miceSaved = 0;

		for(int i = 0; i < mices.size(); i++) {
			if(catPos < mices[i])
				miceSaved++;
			else {
				break;
			}
			catPos += abs(holePos - mices[i]);
		}
		std::cout << miceSaved << std::endl;
	}	
	
	return 0; 
}
