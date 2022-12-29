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
        int n, h, m;
        cin >> n >> h >> m;
        int bedtimeMin = h * 60 + m;
        vector<pair<int, int>> alarms(n);
        vector<int> alarmsInMin(n);
        int h1, m1;
        for(int i = 0; i < n; ++i) {
            cin >> h1 >> m1;
            alarmsInMin[i] = h1*60 + m1;
        }
        sort(alarmsInMin.begin(), alarmsInMin.end());

        if(binary_search(alarmsInMin.begin(), alarmsInMin.end(), bedtimeMin)) {
            cout << 0 << " " << 0 << "\n";
        }
        else {
            int ans;
            if(bedtimeMin > alarmsInMin.back()) {
                ans = 1440 - bedtimeMin + alarmsInMin[0];
            }
            else {
                ans = *upper_bound(alarmsInMin.begin(), alarmsInMin.end(), bedtimeMin) - bedtimeMin;
            }
            cout << ans / 60 << " " << ans % 60 << "\n";
        }

    }	
    
    return 0; 
}
