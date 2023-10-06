// accepted
// https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/C
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y)  
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
const int MOD = 1000000007; // 10^9 - 7 

pair<bool, int> solve(int sum, vector<int>& a) {
	int count = 0;
	int item = LONGINF;

	for(int i = 0, j = a.size() - 1; i < a.size() / 2 + 1; ++i, --j) {
		if(i == j) item = a[i];
		else if(a[i] + a[j] == sum) continue;
		if(a[i] + a[j - 1] == sum) {
			item = a[j];
			j--;
		}
		else if(a[i + 1] + a[j] == sum) {
			item = a[i];
			i++;
		}
		count++;
		if(count > 1)
			return {false, -1};
	}

	return {true, item};
}

int32_t main() { 
	FASTIO;
    int t;
    cin >> t;
    int num_case = 1;
    while (t--) {
		int n;
		cin >> n;

		vector<int> a(n*2 - 1);
		for(int i = 0; i < a.size(); ++i) {
			cin >> a[i];
		}

		sort(a.begin(), a.end());

		vector<int> s(4);
		vector<pair<bool, int>> p(4);
		int ans = LONGINF;

		cout << "Case #" << num_case << ": ";
		
		if(n == 1) {
			cout << 1 << "\n";
		}
		else {

			if(n == 2) {
				s[0] = a[0] + a.back();
				s[1] = a[0] + a[1];
				s[2] = a[1] + a.back();
			}
			
			else {
				s[0] = a[0] + a[a.size() - 1];
				s[1] = a[1] + a[a.size() - 1];
				s[2] = a[0] + a[a.size() - 2];
				s[3] = a[1] + a[a.size() - 2];
			}
			

			for(int i = 0; i < 4; ++i) {
				p[i] = solve(s[i], a);
				if(p[i].first) {
					int comp = s[i] - p[i].second;
					if(comp > 0)
						ans = min(ans, comp);
				}
			}		

			if(ans == LONGINF) {
				cout << "-1\n";
			}
			else {
				cout << ans << "\n";
			}
		}

        num_case++;
    }
	
	return 0; 
}
