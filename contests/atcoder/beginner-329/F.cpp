// O(n) using pointers and only
// swapping from small to large
// https://atcoder.jp/contests/abc329/tasks/abc329_f
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
#define int long long 
const int MOD = 1e9 + 7; // 10^9 + 7 
 
int32_t main() { 
    FASTIO;

    int n, q;
    cin >> n >> q;
    vector<set<int>*> boxes(n+1);
    for(int i = 1; i <= n; ++i) {
        int color;
        cin >> color;
        boxes[i] = new set<int>;
        boxes[i]->insert(color);
    }
    while (q--) {
        int a,b;
        cin >> a >> b;
        
        //transfer the colors from the smaller to the larger set
        if(boxes[a]->size() <= boxes[b]->size()) {
            for(int color : *boxes[a]) {
                boxes[b]->insert(color);
            }
        }
        else {
            for(int color : *boxes[b]) {
                boxes[a]->insert(color);
            }
            
            // swap
            boxes[b] = boxes[a];        
        }
         
        boxes[a] = new set<int>;

        cout << boxes[b]->size() << "\n";
    }

    return 0; 
}
