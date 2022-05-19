
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
// 		k == numOperations
// 		traverse n looking for an elem greater than k and keep max elem
// 		when found, reduce max elem from k and keep last index
// 		then traverse: reduce k from greater than k
// 		traverse string: from 0 to index turn everyone < maxElem into a
// 		from 0 to last turn everyone < greater and > next into next
		int strSize, numOperations;
		int firstCharGreater = 0;
		int maxElem = 0;
		int idx = -1;
		string s;
		cin >> strSize >> numOperations;
		cin >> s;
		for(int i = 0; s[i] - 'a' <= numOperations && i < strSize; ++i) {
			maxElem = max(maxElem, s[i] - 'a');
			idx = i;
		}
		// everyone from 0 to idx is gonna be turned into a
		for(int i = 0; i < strSize; ++i) {
			if(s[i] - 'a' <= maxElem)
				s[i] = 'a';
		}
		numOperations -= maxElem;
		char greater = s[idx+1];
		char next = greater - numOperations;
		// from 0 to last turn everyone < greater and > next into next
		for(int i = 0; numOperations && i < strSize; ++i) {
			if(s[i] <= greater && s[i] > next) s[i] = next;
		}
		cout << s << endl;
    }
	return 0; 
}