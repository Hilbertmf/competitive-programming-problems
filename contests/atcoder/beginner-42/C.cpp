// https://atcoder.jp/contests/abc042/tasks/arc058_a
// accepted
// O(n), n <= 1e5
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long 
const int MOD = 1e9 + 7; // 10^9 + 7 

bool likes(int n, set<char> d) {
    string s = to_string(n);
    for(char c : s) {
        if(d.find(c) == d.end()) return false;
    }
    return true;
}

int32_t main() { 
    FASTIO;
    int n, k;
    cin >> n >> k;
    set<char> d {'0','1','2','3','4','5','6','7','8','9'};

    vector<int> dislikes(k);
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        char c = '0' + num;
        if(d.find(c) != d.end())
            d.erase(d.find(c));
    }

    vector<int> nums;
    int ans;

    for(int i = n; i <= 1e5; ++i) {
        if(likes(i, d)) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";

    return 0; 
}
