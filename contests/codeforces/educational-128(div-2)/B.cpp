// accepted
// https://codeforces.com/contest/1680/problem/B
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
    int rows, cols;

    while (t--) {
        cin >> rows >> cols;
        vector<string> field(rows);
        vector<pair<int, int>> robots;
        bool possible = true;

        int row = 0;
        for(auto &s : field) {
            int col = 0;
            cin >> s;

            for(const auto &c : s) {
                if(s[col] == 'R')	{
                    robots.push_back(make_pair(row, col));
                }
                
                ++col;
            }
            ++row;
        }
        
        for(int i = 0; i < robots.size(); ++i) {
            
            for(int j = 0; possible && j < robots.size(); ++j) {
                if(i == j) continue;
                if(robots[j].first < robots[i].first || robots[j].second < robots[i].second)
                    possible = false;
            }
            if(possible) break;
        }

        if(possible) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }	

    return 0; 
}
