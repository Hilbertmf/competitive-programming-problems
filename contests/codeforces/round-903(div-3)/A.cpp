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
#define int long long
 
vector<int> z_func(string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

bool isCompatible(string& a, string& b) {
    string cmp = b;
    cmp += "$";
    cmp += a;
    vector<int> z = z_func(cmp);

    for(int i = b.size() + 1; i < z.size(); ++i) {
        if(z[i] == b.size()) 
            return true;
    }

    return false;
}

int32_t main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int n1, n2;
		cin >> n1 >> n2;
		string x, s;
		cin >> x >> s;

		int op;
		bool possible = false;

		for(op = 0; op <= 1 || x.size() < s.size() * 5; ++op) {
			if(isCompatible(x, s)) {
				possible = true;
				break;
			}

			x += x;
		}


		if(possible) {
			cout << op << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
	
	return 0; 
}
