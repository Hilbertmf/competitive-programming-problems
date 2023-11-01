// https://codeforces.com/contest/1883/problem/E
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

vector<int> powers_of_2(37);

int calcNumOperations(int init, int target) {
    int left = 0, right = 37;
    int pos = MID(left, right);

    while(left <= right) {
        if(init * powers_of_2[pos] >= target && (pos == 0 ||
            init * powers_of_2[pos - 1] < target)) {
            return pos;
        }
        else if(init * powers_of_2[pos] < target) {
            left = pos + 1;
        }
        else {
            right = pos - 1;
        }
        pos = MID(left, right);
    }
    return -1;
}

int32_t main() { 
    FASTIO;
    int t;
    cin >> t;

    map<int, int> map_2;
    powers_of_2[0] = 1;
    map_2[0] = 1;
    for(int i = 1; i < powers_of_2.size(); ++i) {
        powers_of_2[i] = powers_of_2[i - 1] << 1;
        map_2[powers_of_2[i]] = i;
    }

    while (t--) {

        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        vector<int> ops_to_next(n);

        for(int i = 1; i < n; ++i) {
                        
            if(nums[i] < nums[i - 1]) {
                ops_to_next[i] = calcNumOperations(nums[i], nums[i - 1]);
            }
        }

        // transform ops_to_next in the accumulated sum vector of itself for decreasing segments
        // and get the necessary operations to keep the sequence non-decreasing for the rest

        for(int i = 1; i < n; ++i) {
            if(nums[i] <= nums[i - 1]) {
                ops_to_next[i] += ops_to_next[i - 1];
            }
            // prev elem gets greater than curr
            else if(ops_to_next[i - 1] > 0) {
                
                int div = nums[i] / nums[i - 1];

                // num[i-1] does not exceed nums[i]
                if(ops_to_next[i - 1] <= 36 &&
                powers_of_2[ops_to_next[i - 1]] < div) continue;

                int needless_op = map_2.lower_bound(div)->second;
                ops_to_next[i] += ops_to_next[i - 1] - needless_op;

                if(map_2.find(div) == map_2.end())
                    ops_to_next[i]++;

            }
            
        }

        cout << accumulate(ops_to_next.begin(), ops_to_next.end(), 0LL) << "\n";
        
    }

    return 0;
}