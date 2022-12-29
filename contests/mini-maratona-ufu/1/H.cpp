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
	int q;
	cin >> q;
	bool goodHash = true;
	set<string> hashs;
	while(q-- && goodHash) {
		string s;
		cin >> s;
		if(hashs.find(s) != hashs.end()) {
			goodHash = false;
		}
		else {
			hashs.insert(s);
		}
	}

	if(goodHash) {
		cout << "A funcao eh boa." << "\n";
	}
	else {
		cout << "A funcao nao eh boa." << "\n";
	}
	
	return 0; 
}
