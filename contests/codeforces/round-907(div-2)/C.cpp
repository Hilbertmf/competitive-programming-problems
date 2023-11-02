// https://codeforces.com/contest/1891/problem/C
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
#define int long long
 
int32_t main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> count;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            count[a[i]]++;
        }

        sort(a.begin(), a.end());
        int op = 0, x = 0;

        for(int i = 0, j = n - 1; i < n && i <= j && j >= 0;) {
            
            if(i == j) {
                if(a[i] == 1) {
                    op++;
                }
                else if(a[i] > 1) {

                    if(x >= a[i]) {
                        op++;
                    }
                    else if(a[i] - x == 1) {
                        op += x;
                        op += 2;
                    }
                    else {

                        op += x;
                        int rem = a[i] - x;
                        if(rem % 2 == 0) {
                            op += rem / 2 + 1;
                        }
                        else {
                            op += rem / 2 + 2;
                        }
                    }

                }
                break;
            }
            else if(x + a[i] >= a[j]) {

                op += a[j] + 1;
                a[i] -= a[j] - x;
                x = 0;
                a[j] = 0;
                --j;
            }
            else {
                x += a[i];
                a[i] = 0;
                i++;
            }

        }

        cout << op << "\n";

    }
    
    return 0; 
}
