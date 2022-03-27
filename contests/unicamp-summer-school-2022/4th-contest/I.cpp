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
 
int main() { 
	FASTIO;
	
  int n;
  std::cin >> n;

  bool det[n];
  for(int i = 0; i < n; i++) {
    string str;
    std::cin >> str;
    if(str == "TRUTH") det[i] = true;
    else det[i] = false;
  }

  bool last = det[n-1];
  bool ans = last;
  for(int i = n - 2; i >= 0; i--) {
    if(last) ans = det[i];
    else ans = !det[i];
    last = ans;
  }

  if(ans) std::cout << "TRUTH" << std::endl;
  else std::cout << "LIE" << std::endl;
	return 0; 
}
