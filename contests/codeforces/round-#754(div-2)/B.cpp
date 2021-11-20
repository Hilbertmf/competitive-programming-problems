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
		int length;
		string str;
		std::cin >> length;
		std::cin >> str;	
		string sortedStr = str;
		sort(sortedStr.begin(), sortedStr.end());
		int count = 0;
		if(str == sortedStr)
			std::cout << 0 << std::endl;
		else {
			vector<set<int>> seqs;
			while (str != sortedStr) {
				int j = str.size() - 1;
				for(int i = 1; i < str.size() && j >= 0; i++) {
					if(str[i] < str[i-1]) {
						while (str[j] > str[i-1]) {
							j--;
						}
						char aux;
						aux = str[j];
						str[j] = str[i-1];
						str[i-1] = aux;
						seqs[count].insert(i);
						seqs[count].insert(j+1);
						j--;
					}
				}
				count++;
			}
			std::cout << count << " ";
			for(int i = 0; i < count; i++) {
				std::cout << seqs[i].size() << " ";
				for(auto it = seqs[i].begin(); it != seqs[i].end(); it++) {
					std::cout << *it << " ";
				}
			}
		}
		// std::cout << sortedStr << std::endl;
	}
	 
	//int objs[num] = {0}; 
	return 0; 
}
