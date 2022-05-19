// wrong answer
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

bool isOdd(int n) {
	return n % 2 != 0;
}

int main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cost = 0;
		vector<int> lengths;
		vector<int> distancesOddLengths;
		lengths.reserve(n);
		int repetitions = 1;
		int numOperations = 0;

		for(int i = 0; i < n - 1; ++i) {
			if(s[i] == s[i+1]) {
				repetitions++;
			}
			else {
				lengths.push_back(repetitions);
				repetitions = 1;
			}
		}
		lengths.push_back(repetitions);
		int numSegments = lengths.size();

		for(int i = 0; i < lengths.size(); ++i) {
			if(isOdd(lengths[i])) {
				int j;
				for(j = i + 1; j < lengths.size(); ++j) {
					if(isOdd(lengths[j])) {
						int dist = j - i;
						numOperations += dist;
						numSegments -= (dist / 2) * 2;
						if(dist == 1 || lengths[i] == 1) 
							numSegments--;
						break;
					}
				}
				i = j;
			}
		}

		cout << numOperations << " " << numSegments << "\n";
	
	}	
	
	return 0; 
}