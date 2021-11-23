#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sirestSumeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 


int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		long long k, msgsToBan;
		std::cin >> k >> msgsToBan;

		long long sumPa = (k*(k+1))/2;
		long long numMsgs = 2*k - 1;
		long long numEmojis = (k-1)*k + k;
		
		long long answer = 0;
		if(msgsToBan == 1) {
			std::cout << 1 << std::endl;
			continue;
		}
		if(msgsToBan < numEmojis) {
			if(msgsToBan <= sumPa) {
				answer = ceil((sqrt(1 + 8*msgsToBan) - 1)/2);
				std::cout << answer << std::endl;
			}
			else {
				// invert the ap
				answer += k;
				msgsToBan -= sumPa;
				if(msgsToBan == 1 || msgsToBan == k-1) {
					answer++;
				}
				else {
					long long complementSum = abs(sumPa - (msgsToBan + k));
					long long complement = ceil((sqrt(1 + 8*complementSum) - 1)/2);
					int restSum = k - complement;
					answer += restSum;
				}
				std::cout << answer << std::endl;
			}
		}
		else {
			answer = numMsgs;
			std::cout << answer << std::endl;
		}
	}
	
	return 0; 
}
