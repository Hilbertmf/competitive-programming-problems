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

    int d, num_a, num_b;
    cin >> d >> num_a >> num_b;
    vector<int> a(num_a);
    vector<int> b(num_b);

    for(int i = 0; i < num_a; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < num_b; ++i) {
        cin >> b[i];
    }

    int count = 0;
    int p1 = 0, p2 = 0;

    while (p1 < num_a || p2 < num_b) {
        if(p1 < num_a && a[p1] <= d) {
            d -= a[p1];
            p1++;
        }
        else if(p2 < num_b) {
            d += b[p2];
            p2++;
        }
        else if(p2 == num_b && (p1 >= num_a || d < a[p1]))
            break;
        count++;
    }

    cout << count << "\n";


    return 0; 
}
