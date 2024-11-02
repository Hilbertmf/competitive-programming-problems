#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;

    int n, s;
    cin >> n >> s;
    vector<int> points(n);
    for(auto &p : points) cin >> p;
    

    unordered_set<int> st;
    int sum = 0;
    bool exists = false;
    int j = 0, count = 0;
    for(int i = 0; i < n && !exists; ++i) {
        sum += points[i];

        while (sum > s && j < i) {
            sum -= points[j];
            j++;
        }

        if (points[i] > s) {
            sum = 0;
            j = i + 1;
        }
        else if (sum == s)
            exists = true;
        // int comp = sum - s;

        // if (st.find(comp) != st.end() ||
        //     sum == s)
        //     exists = true;

        // st.insert(sum);
    }

    // int comp = sum - s;
    // if (st.find(comp) != st.end() ||
    //     sum == s)
    //     exists = true;

    if(exists) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}


class Solution {
public:
    int subarraySum(vector<int>& nums, int s) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        bool exists = false;
        int ans = 0;
        for(int i = 0; i < n && !exists; ++i) {
            sum += nums[i];
            int comp = sum - s;

            if (mp.find(comp) != mp.end())
                ans += mp[comp];
            if (sum == s)
                ans++;

            mp[sum]++;
        }

        return ans;
        
    }
};
