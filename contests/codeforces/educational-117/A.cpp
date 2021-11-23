// avv
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
int dist(pair<int, int> a, pair<int, int> b) {
	int x1, x2, y1, y2;
	x1 = a.first;
	y1 = a.second;
	x2 = b.first;
	y2 = b.second;
	return abs(x1 - x2) + abs(y1 - y2);
}
int main() { 
	FASTIO;
	int t;
	std::cin >> t;

	while (t--) {
		pair<int, int> A, B;
		int x, y;
		std::cin >> x >> y;
		A = make_pair(0, 0);
		B = make_pair(x, y);

		int distAB = dist(A, B);
		if(x == 0 && y == 0) {
			std::cout << "0 0" << std::endl;
			continue;
		}
			
		if(distAB % 2 != 0) {
			std::cout << "-1 -1" << std::endl;
			continue;
		}

		if(x == 0 || y == 0) {
			if(x == 0) {
				std::cout << "0 " << distAB/2 << std::endl;
			}
			else if(y == 0) {
				std::cout << distAB/2<< " 0"  << std::endl;
			}
		}
		else if(x > y) {
			std::cout << (distAB/2) - 1 << " " << 1 << std::endl;
			continue;
		}
		else {
			std::cout << 1 << " " << (distAB/2) - 1 << std::endl;
			continue;
		}


	}
	
	return 0; 
}
