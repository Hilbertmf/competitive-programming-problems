// accepted
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
	cin >> t;
	while (t--) {
		int ans;
		int a1, a2, a3;
		std::cin >> a1 >> a2;
		std::cin >> a3;

		int d = a1 + a3 - 2*(a2);
		int dev = abs(d);
		// DEBUG(d);
		// DEBUG(dev);
		if(dev % 3 != 0)
			std::cout << 1 << std::endl;
		else
			std::cout << 0 << std::endl;
		// while (dev > 1) {
		// 	if(d < 0) {
		// 		a2--;
		// 		if(a1 < a3)
		// 			a1++;
		// 		else
		// 			a3++;
		// 	}
		// 	else {
		// 		a2++;
		// 		if(a1 > a3)
		// 			a1--;
		// 		else
		// 			a3--;
		// 	}
		// 	d = a1 + a3 - 2*(a2);
		// 	dev = abs(d);
		// }

		// std::cout << dev << std::endl;
	}
	 
	//int objs[num] = {0}; 
	return 0; 
}
