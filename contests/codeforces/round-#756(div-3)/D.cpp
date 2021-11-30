// https://codeforces.com/contest/1611/problem/D
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

// you dont need to create the tree, you just have to check some basic conditions

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		bool impossible = false;
    int numVertices, root;
    std::cin >> numVertices;
    vector<int> parents(numVertices+1), perm(numVertices+1), dist(numVertices+1), weights(numVertices+1);

    for(int i = 1; i <= numVertices; i++) {
      std::cin >> parents[i];
      // the root's parent is itself
      if(i == parents[i]) root = i;
    }

    for(int i = 1; i <= numVertices; i++) 
      std::cin >> perm[i];

    // distance from root is zero
    dist[perm[1]] = 0;
    weights[root] = 0;

    // the distances are going to increase based on the permutation order
    for(int i = 2; i <= numVertices; i++) 
        dist[perm[i]] = dist[perm[i-1]] + 1;

    for(int i = 1; i <= numVertices; i++) {
      weights[i] = dist[i] - dist[parents[i]];
      // if dist to child is less than dist to its parent, then its impossible
      if(dist[i] <= dist[parents[i]] && i != root) {
        impossible = true;
        break;
      }
    }
    
    if(perm[1] != root) impossible =  true;
    
    if(impossible) std::cout << -1;
    else {
      for(int i = 1; i <= numVertices; i++) {
        std::cout << weights[i];
        if(i != numVertices) cout << " ";
      }
    }
    
    std::cout << "\n";
	}
	
	return 0; 
}
