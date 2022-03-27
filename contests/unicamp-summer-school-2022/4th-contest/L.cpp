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
  long long k;
  std::cin >> k;

  string str;
  std::cin >> str;
  string resStr = str;


  vector<long long> powers2(61);
  powers2[0] = 1;
  powers2[1] = 2;
  for(int i = 2; i < 61; i++) {
    powers2[i] = powers2[i-1] * 2;
  }

  auto it = upper_bound(powers2.begin(), powers2.end(), k);

  int maxNumDigits = it - powers2.begin();
  int minBitsToRemove = str.size() - maxNumDigits;
  int bits = 0;
  bool atFirstDigit = true;
  
  std::string::size_type sz = 0;   // alias of size_t
  string start;
  int startDigit;


  for(int i = 0; i < str.size(); i++) {
    if(atFirstDigit) {
      if(str[i+1] == '1') {
        std::cout << "entrou 1" << std::endl;
        bits++;
        resStr = str.substr(i+1);
        DEBUG(bits);
        DEBUG(resStr);
        long long res = stoll(resStr, &sz, 2);
        if(res <= k) break;
        
      }
      else {
        std::cout << "entrou 2" << std::endl;
        atFirstDigit = false;
        string start = resStr;
        startDigit = i+1;
      }
    }
    else {
      std::cout << "entrou 3" << std::endl;
      DEBUG(bits);
      DEBUG(resStr);
      long long res = stoll(resStr, &sz, 2);
      DEBUG(res);
      if(res <= k) break;
      
      
      resStr = resStr.erase(startDigit, 1);
      bits++;
      
    }
  }
	
  std::cout << bits << std::endl;
	return 0; 
}
