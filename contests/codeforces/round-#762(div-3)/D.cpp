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

int charToInt(char c) {
	return c - '0';
}

string removeLeadingZeros(string str) {
	str.erase(0, str.find_first_not_of('0'));
	return str;
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
    std::cout << "t" << std::endl;
    int numShops, numFriends;
    std::cin >> numShops >> numFriends;
    int table[numShops][numFriends];
    for(int i = 0; i < numShops; i++) {
      for(int j = 0; j < numFriends; j++) {
        std::cin >> table[i][j];
      }
    }
    vector<set<int>> friendsCols(numFriends);
    if(numFriends > numShops) {
      
      
      for(int i = 0; i < numShops; i++) {
        for(int j = 0; j < numFriends; j++) {
          friendsCols[j].insert(table[i][j]);
        }
      }

      std::cout << "alfa:" << std::endl;
      int alfa = INF;
      for(int i = 0; i < numFriends; i++) {
        // std::cout << "friend " << i << ": " << *friendsCols[i].rbegin() << std::endl;;
        alfa = min(*friendsCols[i].rbegin(), alfa);
      }
      cout << "alfa: " << alfa << "\n";
    }
  }
  
  return 0;
}