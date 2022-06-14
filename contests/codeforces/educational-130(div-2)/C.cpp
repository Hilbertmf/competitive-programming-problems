// accepted
// https://codeforces.com/contest/1697/problem/C
// time: O(n)
// space: O(n)
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
    int t;
    cin >> t;
    while (t--) {
        int sz;
        cin >> sz;
        string s, t;
        cin >> s >> t;
        bool possible = true;
        vector<int> sMap(3);
        vector<vector<int>> sIndices(3, vector<int>());
        vector<int> tMap(3);
        vector<vector<int>> tIndices(3, vector<int>());
        for(int i = 0; i < sz; ++i) {
            sMap[s[i] - 'a']++;
            sIndices[s[i] - 'a'].push_back(i);
        }
        for(int i = 0; i < sz; ++i) {
            tMap[t[i] - 'a']++;
            tIndices[t[i] - 'a'].push_back(i);
        }

        if(sMap != tMap)
            possible = false;

        for(int i = 0; i < sIndices[0].size() && possible; ++i) { // a
            if(sIndices[0][i] > tIndices[0][i])
                possible = false;
        }

        for(int i = 0; i < sIndices[2].size() && possible; ++i) { // c
            if(sIndices[2][i] < tIndices[2][i])
                possible = false;
        }

        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < sz && ptr2 < sz && possible) {
            if(s[ptr1] == 'b' || t[ptr2] == 'b') {
                if(s[ptr1] == 'b')
                    ++ptr1;
                if(t[ptr2] == 'b')
                    ++ptr2;
            }
            else {
                if(s[ptr1] != t[ptr2])
                    possible = false;
                ++ptr1;
                ++ptr2;
            }            
        }

        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }	
    
    
    return 0; 
}
