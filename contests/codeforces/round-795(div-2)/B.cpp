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

bool lessThan2(const pair<int, int>& kvp) {
    return kvp.second < 2;
}

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        
        int n;
        cin >> n;
        vector<int> sizes(n);
        map<int, int> sizeMap;
        bool possible = true;

        for(auto &size : sizes) {
            cin >> size;
            sizeMap[size]++;
        }

        if(find_if(sizeMap.begin(), sizeMap.end(), lessThan2) != sizeMap.end())
            possible = false;
        
        if(!possible)
            cout << "-1" << "\n";

        else {
            vector<int> res(n);

            int i, j;
            for(i = 0; i < n - 1; ++i) {
                j = i + 1;

                while(j < n && sizes[i] == sizes[j]) {
                    res[j] = j;
                    ++j;
                }

                --j;
                res[i] = j + 1;
                i = j;
            }

            cout << res[0];
            for(int i = 1; i < n; ++i) {
                cout << " " << res[i];
            }
            cout  << "\n";
        }
    }
    
    return 0; 
}
