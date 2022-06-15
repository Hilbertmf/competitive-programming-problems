// accepted
// https://codeforces.com/contest/1692/problem/G
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (long long)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const long long MOD = 1000000007; // 10^9 - 7  

bool restartWindow(int& left, long long k, vector<long long>& arr, deque<long long>& window) {
    long long len = arr.size();
    window.clear();
    window.push_back(arr[left]);
    for(; window.size() < k + 1 && left < len - 1; ++left) {
        if(arr[left] < 2 * arr[left + 1]) {
            window.push_back(arr[left + 1]);
        }
        else {
            window.clear();
            window.push_back(arr[left]);
        }
    }

    return window.size() == k + 1;
}

int main() { 
    FASTIO;
    long long t;
    cin >> t;
    while (t--) {
        long long len, k, ans = 0;
        cin >> len >> k;
        vector<long long> arr(len);
        for(long long i = 0; i < len; ++i) cin >> arr[i];
        
        deque<long long> window;
        int left = 0;

        bool successful = restartWindow(left, k, arr, window);
        if(successful) ans++;

        left++;		
        for(; left < len; ++left) {
            if(arr[left] * 2 > window.back()) {
                window.pop_front();
                window.push_back(arr[left]);
                ans++;
            }
            else {
                successful = restartWindow(left, k, arr, window);
                if(successful) ans++;
            }
        }

        cout << ans << "\n";
    }	
    
    return 0; 
}
