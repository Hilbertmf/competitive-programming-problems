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
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;

    string s;
    int k;
    cin >> s >> k;

    int start = 0;

    for(int start = 0; start < k; ++start) {

        if(start + k >= s.size()) continue;

        priority_queue<char, vector<char>, greater<char>> min_heap;
        for(int i = start; i < s.size(); i += k) {
            min_heap.push(s[i]);
        }
        for(int i = start; i < s.size(); i += k) {
            s[i] = min_heap.top();
            min_heap.pop();
        }
    }

    cout << s << "\n";


    return 0;

}
