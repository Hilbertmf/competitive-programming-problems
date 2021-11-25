// TLE
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

bool isKalindrome(vector<int> vec, int x) {
	if(vec.size() == 1) return true;

	int i = 0, j = vec.size() - 1;
	while (i < j) {
		while (vec[i] != vec[j] && (vec[i] == x || vec[j] == x)) {
			if(vec[i] == x) i++;
			else j--;
		}
		if(vec[i] != vec[j] && vec[i] != x && vec[j] != x) return false;
		i++;
		j--;
	}
	return true;
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		vector<int> seq(n);
		set<int> nums;
		bool answer = false;
		for(int i = 0; i < n; i++) {
			std::cin >> seq[i];
			nums.insert(seq[i]);
		}

		if(!((seq.size() > 3 && (nums.size() > (seq.size()/2) + 1)))) {
			for(auto it = nums.begin(); it != nums.end(); it++) {
				int x = *it;
				if(isKalindrome(seq, x)) {
					answer = true;
					break;
				}
			}
		}
		if(answer) {
			std::cout << "YES" << std::endl;
			continue;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
	
	return 0; 
}
