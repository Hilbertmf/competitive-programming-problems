// https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/problems/A2
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
    a += a;
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
    int num_case = 1;
    while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		vector<int> b(n);
        string a_str;
        string b_str;
        bool allEqual = true;

		for(int i = 0; i < n; ++i) {
			cin >> a[i];
            a_str += to_string(a[i]);
            if(i > 0 && a[i] != a[i - 1])
                allEqual = false;
		}
		
		for(int i = 0; i < n; ++i) {
			cin >> b[i];
            b_str += to_string(b[i]);
		}
        
		bool aEqualB = a == b;
        bool possible = aEqualB || isCompatible(a_str, b_str);

		cout << "Case #" << num_case << ": ";
		
		
        if(allEqual) {
            cout << "YES" << "\n";
        }
        
        else if(n == 2) {
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
