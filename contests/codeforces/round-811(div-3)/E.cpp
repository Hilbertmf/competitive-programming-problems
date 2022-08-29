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
        int n;
        cin >> n;
        vector<long long> arr(n);
        vector<unordered_set<long long>> set(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        
        sort(arr.begin(), arr.end(), greater<int>());
        long long greatestOddTen = -1;
        long long greatestEvenTen = -1;
        for(int i = 0; i < n; ++i) {
            if((arr[i] / 10) & 1) {
                greatestOddTen = max(greatestOddTen, arr[i] / 10);
            }
            else {
                greatestEvenTen = max(greatestEvenTen, arr[i] / 10);
            }
        }

        long long greatestTen = max(greatestOddTen, greatestEvenTen);
        greatestTen++;

        for(int i = 0; i < n; ++i) {
            long long tmp = arr[i];
            set[i].insert(tmp);
            while(tmp + (tmp % 10) < arr[i] + 20 && tmp % 10 != 0) {
                tmp = tmp + (tmp % 10);
                set[i].insert(tmp);
            }
            
            for(auto &elem : set[i]) {
                int unit = elem % 10;
                if(unit == 0) continue;
                long long ten = elem / 10;
                if(ten & 1) {
                    if(greatestTen & 1)
                        ten = greatestTen;
                    else
                        ten = greatestTen + 1;
                }
                else {
                    if(greatestTen & 1)
                        ten = greatestTen + 1;    
                    else
                        ten = greatestTen;
                }
                set[i].insert(ten * 10 + unit);
            }
        }

        bool possible = true;
        for(int i = 0; i < n - 1; ++i) {
            int count = 0;
            for(auto &elem : set[i]) {
                if(set[i+1].find(elem) != set[i+1].end()) {
                    count++;
                    break;
                }
            }
            if(count == 0) {
                possible = false;
                break;
            }
        }

        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }	
    
    
    return 0; 
}
