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

int charToInt(char c) {
	return c - '0';
}

string removeLeadingZeros(string str) {
	str.erase(0, str.find_first_not_of('0'));
	return str;
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		string a, s, str, b;
		bool possible = true;
		b = "";
		cin >> a >> s;
		int bDigit;
		if(a.size() > s.size()) possible = false;

		for(int aIdx = a.size() - 1, sIdx = s.size() - 1;
		(aIdx >= 0 || sIdx >= 0) && a.size() <= s.size();
		aIdx--, sIdx--) {
			int aDigit = charToInt(a[aIdx]), sDigit = charToInt(s[sIdx]);
			if(aIdx < 0) aDigit = 0;
			// DEBUG(aDigit);
			// DEBUG(sDigit);
			// DEBUG(aIdx);
			// DEBUG(sIdx);
			if(aDigit > sDigit) {
				if((a.size() >= s.size())
					|| (sIdx > 0 && (s[sIdx-1] != '1'))
					|| (sIdx == 0)) {
					possible = false;
					break;
				}
				sDigit += 10;
				sIdx--;
				bDigit = sDigit - aDigit;
				char aux = '0' + bDigit;
				b = aux + b;
				// DEBUG(b);
			}
			else {

				bDigit = sDigit - aDigit;
				char aux = '0' + bDigit;
				b = (bDigit == 0 && sIdx == 0) ? b : aux + b;
				// DEBUG(b);
			}
			// DEBUG(b);
		}
		if(possible) {
			std::cout << removeLeadingZeros(b) << std::endl;
		}
		else std::cout << -1 << std::endl;
	}
	
	return 0; 
}
