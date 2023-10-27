// https://codeforces.com/contest/1883/problem/C
// accepted
#include <bits/stdc++.h>
using namespace std; 
#define DEBUG(x) std::cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
#define int long long

int32_t main() { 
    int t;
    cin >> t;
    vector<vector<int>> factors(4, vector<int>());
    factors[0] = {2,4,6,8,10,12}; // 2
    factors[1] = {3,6,9,12}; // 3
    factors[2] = {4,8,12}; // 4
    factors[3] = {5,10,15}; // 5

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        int pos = k - 2;
        int ops = INF;
        int divides_2 = 0;

        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
            if(nums[i] % k == 0) ops = 0;
            if(nums[i] % 2 == 0) divides_2++;
        }

        if(ops == 0 || (k == 4 && divides_2 >= 2)) {
            ops = 0;
        }
        else {

            // test for k
            for(int i = 0; i < n; ++i) {
                int diff = INF;
                for(auto &fac : factors[pos]) {
                    if(fac < nums[i]) continue;
                    diff = min(diff, fac - nums[i]);
                }
                ops = min(ops, diff);
            }
            
            if(k == 4 && divides_2 < 2) {
                priority_queue<int, vector<int>, greater<int>> pq;

                for(int i = 0; i < n; ++i) {				
                    if(nums[i] % 2 == 0) continue;
                    int curr_diff = INF;
                    
                    for(auto &fac : factors[0]) {
                        
                        if(fac < nums[i]) continue;
                        curr_diff = min(curr_diff, fac - nums[i]);
                    }

                    pq.push(curr_diff);
                }

                pair<int, int> p;
                p.first = pq.top();

                if(divides_2 == 1) {
                    ops = p.first;
                }
                else if(divides_2 == 0) {
                    pq.pop();
                    p.second = pq.top();
                    ops = min(ops, p.first + p.second);
                }
            }

        }

        std::cout << ops << "\n";

    }	
    
    return 0; 
}
