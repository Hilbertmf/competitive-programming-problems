// wrong answer
// https://codeforces.com/contest/1702/problem/E
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (long long)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const long long MOD = 1000000007; // 10^9 - 7 



int main() { 
    FASTIO;
    long long t;
    cin >> t;
    while (t--) {
        long long numDominoes;
        cin >> numDominoes;
        vector<pair<long long, long long>> dominoes(numDominoes);
        map<int, int> freq;
        for(long long i = 0; i < numDominoes; ++i) {
            cin >> dominoes[i].first >> dominoes[i].second;
            freq[dominoes[i].first]++;
            freq[dominoes[i].second]++;
        }
        bool possible = false;

        for(auto &kvp : freq) {
            if(kvp.second > 2) {
                possible = false;
                break;
            }
        }

        unordered_set<long long> s1;
        unordered_set<long long> s2;
        s1.reserve(numDominoes);
        s2.reserve(numDominoes);
        
        for(auto &p : dominoes) {
            if(p.first == p.second) {
                possible = false;
                break;
            }
            if(s1.find(p.first) == s1.end() && s1.find(p.second) == s1.end()) {
                s1.insert(p.first);
                s1.insert(p.second);
            }
            else if(s2.find(p.first) == s2.end() && s2.find(p.second) == s2.end()) {
                s2.insert(p.first);
                s2.insert(p.second);
            }
        }

        if(s1.size() + s2.size() == numDominoes * 2) possible = true;
        
        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }	
    
    return 0; 
}
