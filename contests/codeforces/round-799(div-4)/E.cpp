// accepted
// https://codeforces.com/contest/1692/problem/E
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
        int n, targetSum, op = 0;
        cin >> n >> targetSum;
        vector<int> arr(n);
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }
        
        if(targetSum > sum) {
            cout << "-1" << "\n";
            continue;
        }
        
        queue<int> window;
        int winSum = 0;
        int left = 0;
        for(; left < n && winSum <= targetSum; ++left) {
            if(winSum == targetSum && arr[left])
                break;
            
            window.push(arr[left]);
            winSum += arr[left];
        }

        int windowSize = window.size();

        for(; left < n; ++left) {
            if(arr[left]) {
                while(window.front() == 0)
                    window.pop();
                window.pop();
            }
            window.push(arr[left]);
            windowSize = max(windowSize, (int)window.size());
        }

        cout << n - windowSize << "\n";
    }	
    
    return 0; 
}
