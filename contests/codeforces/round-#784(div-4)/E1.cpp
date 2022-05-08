// accepted
// https://codeforces.com/contest/1669/problem/E
// time: O(nlogn)
// space: O(n)
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (long long)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
 
int main() { 
	FASTIO;
	long long t;
	std::cin >> t;
	while (t--) {
        long long numStrings;
        std::cin >> numStrings;
        vector<string> strings(numStrings);
        long long totalPairs = 0;
        // hashmap of maps of occurrences of chars on s[0] and s[1]
        // each map: index -> position
        unordered_map<char, map<long long, long long>> charsOn0;
        unordered_map<char, map<long long, long long>> charsOn1;
        unordered_map<string, map<long long, long long>> appearances;
 
        for(long long i = 0; i < numStrings; ++i) {
            std::cin >> strings[i];
        }
 
        // populate occurrences
        for(long long i = 0; i < numStrings; ++i) {
            char first = strings[i][0];
            char second = strings[i][1];
            charsOn0[first].insert(make_pair(i, charsOn0[first].size()+1));
            charsOn1[second].insert(make_pair(i, charsOn1[second].size()+1));
        }
 
 
        // populate appearances
        for(long long i = 0; i < numStrings; ++i) {
            appearances[strings[i]].insert(make_pair(i, appearances[strings[i]].size()+1));
        }
 
        for(long long i = 0; i < numStrings; ++i) {
            string s = strings[i];
            char first = s[0];
            char second = s[1];
            long long pairs = 0;
 
            long long count0 = charsOn0[first].size() - charsOn0[first].find(i)->second;
            long long count1 = charsOn1[second].size() - charsOn1[second].find(i)->second;
            pairs += count0;
            pairs += count1;
            long long repetitions = (appearances[s].size() - appearances[s].find(i)->second);
            totalPairs += pairs - 2 * repetitions;
        }
        
        std::cout << totalPairs << std::endl;
    }
 
    return 0;
}