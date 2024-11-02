#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

bool canBePalindrome(vector<int>& arr) {
    map<int, int> count;
    for(auto &num : arr) {
        count[num]++;
    }

    int odd = 0, even = 0;
    for(auto &[k, v] : count) {
        if (v & 1) odd++;
        else even ++;
    }
    return odd <= 1;
}

int getRangeSum(int left, int right,
vector<vector<int>>& prefix, int x) {
    int sum = prefix[right][x];
    if (left > 0)
        sum -= prefix[left - 1][x];
    return sum;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<int> mod(n);
        map<int, int> count;
        map<int, multiset<int>> mp;
        for(int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            arr[i] = num;
            mod[i] = num % k;
            count[num % k]++;
            mp[num % k].insert(num);
        }

        if(!canBePalindrome(mod)) {
            cout << "-1\n";
        }
        else {
            int ans = 0;
            if (canBePalindrome(arr)) {
                cout << 0 << "\n";
            }
            else {
                for(auto &[modu, mst] : mp) {

                    vector<int> tmp(mst.begin(), mst.end());

                    // we have to remove one element to be in the center
                    if (count[modu] & 1) {
                        
                        int sz = count[modu];
                        vector<vector<int>> prefix(sz, vector<int>(2));

                        // 0 or 1:
                        for(int x = 0; x <= 1; ++x) {
                            for(int i = x + 1; i < sz; i += 2) {
                                prefix[i][x] = (tmp[i] - tmp[i - 1]) / k;
                                if (i >= 2)
                                    prefix[i][x] += prefix[i - 2][x];

                            }
                            
                        }

                        int curr_best = INF;
                        // if we remove i:
                        for(int i = 0; i < sz; ++i) {
                            int curr = 0;
                            if(i == 0) {
                                curr = getRangeSum(1, sz - 1, prefix, 1);
                            }
                            else if (i == sz - 1) {
                                curr = getRangeSum(0, i - 1, prefix, 0);
                            }
                            else if (i & 1) { // odd

                                curr += (tmp[i + 1] - tmp[i - 1]) / k;
                                if(i - 2 >= 0)
                                    curr += getRangeSum(0, i - 2, prefix, 0);
                                if (i + 2 < sz)
                                    curr += getRangeSum(i + 2, sz - 1, prefix, 1);
                            }
                            else { // even

                                if (i - 1 >= 0)
                                    curr += getRangeSum(0, i - 1, prefix, 0);
                                if (i + 1 < sz)
                                    curr += getRangeSum(i + 1, sz - 1, prefix, 1);
                            }

                            curr_best = min(curr_best, curr);
                        }
                        
                        ans += curr_best;
                    }
                    else {
                        vector<int> operations;
                        operations.reserve(tmp.size() / 2 + 1);
                        for(int i = 0; i < tmp.size(); i += 2) {
                            int op = (tmp[i + 1] - tmp[i]) / k;
                            operations.push_back(op);
                        }

                        sort(operations.rbegin(), operations.rend());
                        ans += accumulate(operations.begin(), operations.end(), 0);
                    }

                }
                cout << ans << "\n";
            }
            
        }
    }
    
    return 0;
}