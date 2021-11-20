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
void initArray(int arr[], int length, int val) { 
	for (int i = 0; i < length; i++) 
		arr[i] = val; 
	return; 
} 
 
int main() { 
	FASTIO; 
	//ifstream cin("in.txt"); 
	//ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 
	 int t;
	 std::cin >> t;
	 while (t--) {
		int l;
		string s;
		std::cin >> l >> s;
		int nA = -1, nB = 0, nC = 0;
		int ans = -2;
		set<int> answers;
		for(int i = 0; i < s.size(); i++) {
			if(i > 0 && (s[i-1] == 'a' && s[i] == 'a'))
				answers.insert(2);
			if(s[i] == 'a') {
				nA++;
				if(nA == 0) {
					ans = 0;
					nA++;
				}
				else if(nA == 2) {
					ans++;
					// nA = 0;
					// std::cout << "string: " << s << " i = " << i << std::endl;
					
					if(nA > nB && nA > nC) {
						answers.insert(ans);
						// DEBUG(nA);
						// DEBUG(nB);
						// DEBUG(nC);
						// DEBUG(ans);
					}
					nA = 1;
					nB = 0;
					nC = 0;
					ans = 0;
				}
			}
			if(ans != -2) ans++;
			if(s[i] == 'b' && ans != -2) nB++;
			if(s[i] == 'c' && ans != -2) nC++;
		}

		if(answers.size() > 0)
			std::cout << *answers.begin() << std::endl;
		else
			std::cout << -1 << std::endl;
	 }
	 
	//int objs[num] = {0}; 
	return 0; 
}
