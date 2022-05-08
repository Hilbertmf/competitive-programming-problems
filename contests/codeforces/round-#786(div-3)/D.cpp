#include <bits/stdc++.h> 
using namespace std; 
#define MID(l, r) (l + (r - l) / 2)
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		vector<int> a(n);
        bool possible = true;
        for(int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());
        int i;
        if(n % 2 != 0) { //odd
            if(a[0] != sortedA[0]) possible = false;
            i = 1;
        }
        else { //even
            i = 0;
        }

        for(i; possible && i < n; i += 2) {
            pair<int, int> p1 (a[i], a[i+1]);
            pair<int, int> p2 (sortedA[i], sortedA[i+1]);
            pair<int, int> revP2 (p2.second, p2.first);
            
            if(!(p1 == p2 || p1 ==  revP2)) possible = false;
        }
        if(possible) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }

    return 0;
}