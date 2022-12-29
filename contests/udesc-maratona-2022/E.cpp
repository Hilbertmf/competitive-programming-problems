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
 
int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int smAvgInt, smAvgFloat;
        string s;
        cin >> s;
        smAvgInt = stoi(s.substr(0, s.find('.')));
        smAvgFloat = stoi(s.substr(s.find('.') + 1));

        double smAvg = smAvgInt*10 + smAvgFloat;

        int exameScore_int = 250 - 3*smAvg;
        exameScore_int >>= 1;

        printf("%.1lf\n", exameScore_int / 10.0);
    }

    return 0; 
}
