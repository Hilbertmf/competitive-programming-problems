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

void populateSet(unordered_set<string>& st, int num) {
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (i + j + k == num) {
					string tmp = to_string(i) + to_string(j) + to_string(k);
					sort(tmp.begin(), tmp.end());
					st.insert(tmp);
				}
}

int main() { 
	FASTIO;
	int t;
	cin >> t;
	unordered_set<string> possibilites;
	possibilites.reserve(30);
	populateSet(possibilites, 3);
	populateSet(possibilites, 13);
	populateSet(possibilites, 23);

	while (t--) {
		int n;
		cin >> n;
		vector<int> digitsMap(10);
		vector<long long> arr(n);
		int num = 0;
		bool possible = false;
		for(int i = 0; i < n; ++i)  {
			cin >> num;
			int digit = num % 10;
			digitsMap[digit]++;
		}

		for(const auto &s : possibilites) {
			int i = s[0] - '0';
			int j = s[1] - '0';
			int k = s[2] - '0';

			if(i != j && i != k & j != k) {
				if(digitsMap[i] && digitsMap[j] && digitsMap[k]) {
					possible = true;
					break;
				}
			}
			else {
				if(i == j && i == k) {
					if(digitsMap[i] >= 3) {
						possible = true;
						break;
					}
				}
				else if(i == j) {
					if(digitsMap[i] >= 2 && digitsMap[k]) {
						possible = true;
						break;
					}
				}
				else if(j == k) {
					if(digitsMap[i] && digitsMap[j] >= 2) {
						possible = true;
						break;
					}
				}
			}
		}		

		if(possible) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}	
	
	return 0; 
}
