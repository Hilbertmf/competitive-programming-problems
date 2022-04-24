// accepted
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008caa74/0000000000acf079
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
	int numCases;
	std::cin >> numCases;
	for(int c = 1; c <= numCases; c++) {
		double ans = 0;
		double pi = 3.14159265359;

		int r, a, b;
		std::cin >> r >> a >> b;
		int radius = r;
		vector<int> radiusVec;

		for(int i = 1; radius; i++) {
			radiusVec.push_back(radius);
			if(i % 2 != 0) {
				radius *= a;
			}
			else {
				radius /= b;
			}
			
		}
		for(auto &r : radiusVec) {
			ans += pi*r*r;
		}

		printf("Case #%d: %.6f\n", c, ans);
	}
	return 0; 
}
