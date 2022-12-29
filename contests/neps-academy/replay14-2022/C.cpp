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
    int n, a, b;
    cin >> n >> a >> b;
    vector<unordered_set<int>> aliceAndBob(2);
    aliceAndBob[0].reserve(a);
    aliceAndBob[1].reserve(b);
    for(int i = 0; i < a; ++i) {
        int problem;
        cin >> problem;
        aliceAndBob[0].insert(problem);
    }
    for(int i = 0; i < b; ++i) {
        int problem;
        cin >> problem;
        aliceAndBob[1].insert(problem);
    }
    
    map<int, int> solution;

    for(auto &problem : aliceAndBob[0]) {
        if(aliceAndBob[1].find(problem) == aliceAndBob[1].end()) solution[problem] = 0;
    }
    for(auto &problem : aliceAndBob[1]) {
        if(aliceAndBob[0].find(problem) == aliceAndBob[0].end()) solution[problem] = 1;
    }

    int count = 0;
    int curr = solution.begin()->second;

    for(int i = solution.begin()->first; i <= n; ++i) {
        if(aliceAndBob[curr].find(i) == aliceAndBob[curr].end() &&
        aliceAndBob[curr^1].find(i) != aliceAndBob[curr^1].end()) {
            count++;
            curr ^= 1;
        }
        else if(aliceAndBob[curr].find(i) == aliceAndBob[curr].end() &&
        aliceAndBob[curr^1].find(i) == aliceAndBob[curr^1].end()) {
            int nxt = solution.upper_bound(i)->first - 1;
            i = max(i, nxt);
        }
    }

    cout << count << "\n";
    
    return 0; 
}
