// acc
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
    string n_str;
    cin >> n_str;
    int n = stoi(n_str);
    int score = 0;
    for(auto &c : n_str) {
        int digit = c - '0';
        if(digit > 0 && n % digit == 0) score++;
    }

    cout << score << "\n";
    
    return 0; 
}
