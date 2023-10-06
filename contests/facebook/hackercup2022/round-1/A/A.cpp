// https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/problems/A1
// accepted
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y)  
#define INF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
const int MOD = 1000000007; // 10^9 - 7 

int32_t main() { 
	FASTIO;
    int t;
    cin >> t;
    int num_case = 1;
    while (t--) {
		int n, k;
		cin >> n >> k;
		bool possible = true;
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int posB;
		
		for(int i = 0; i < n; ++i) {
			cin >> b[i];
			if(b[i] == a[0]) posB = i;
		}
		
		bool aEqualB = a == b;


		for(int i = 0; i < n && !aEqualB && n > 2; ++i) {
			if(a[i] != b[posB]) {
				possible = false;
				break;
			}
			posB++;
			if(posB >= n) posB = 0;
		}


		cout << "Case #" << num_case << ": ";
		
		if(n == 2) {
			if(aEqualB) {
				if(k % 2 == 0) cout << "YES" << "\n";
				else cout << "NO" << "\n";
			}
			else {
				if(k % 2 == 0) cout << "NO" << "\n";
				else cout << "YES" << "\n";
			}
		}
		else {
			if(!possible) {
				cout << "NO" << "\n";				
			}
			else if(aEqualB) {
				if(k == 1) cout << "NO" << "\n";
				else cout << "YES" << "\n";
			}
			else if(k == 0) {
				cout << "NO" << "\n";
			}
			else {
				cout << "YES" << "\n";
			}
		}

        num_case++;
    }
	
	return 0; 
}
