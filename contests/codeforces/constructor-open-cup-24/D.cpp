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
    int t;
    cin >> t;
    
    while(t--){

        int n, m;
        cin >> n >> m;
        vector<int> skills(n);
        vector<int> diffs(m);
        for(auto &skill : skills) cin >> skill;
        for(auto &diff : diffs) cin >> diff;
        
        int min_s = *min_element(skills.begin(), skills.end());

        vector<int> used_tasks(n);
        bool possible = true;
        for(int i = 0; i < n; ++i) {            
            
            auto it = lower_bound(diffs.begin(), diffs.end(), skills[i]);
            if(it == diffs.end())
                used_tasks[i] = m;
            else if(it == diffs.begin() && *it == skills[i])
                used_tasks[i] = 1;
            else if(it == diffs.begin())
                used_tasks[i] = 0;
            else if(it != diffs.begin()) {
                if(*it != skills[i])
                    --it;
                
                used_tasks[i] = it - diffs.begin() + 1;
            }

            if(i > 0 && used_tasks[i - 1] == used_tasks[i])
                possible = false;
        }

        if (count(used_tasks.begin(), used_tasks.end(), 0) > 0) {
            possible = false;
        }

        if(possible) {
            int ans = 0;
            vector<int> indices(n);

            for(int i = n - 1; i >= 0; --i) {
                auto it = upper_bound(diffs.begin(), diffs.end(), skills[i]);
                --it;
                indices[i] = it - diffs.begin() + 1;
            }

            cout << n << "\n";
            for(auto &index : indices) {
                cout << index << " ";
            }
            cout << "\n";
        }
        else {
            cout << -1 << "\n";
        }

    }
    
    return 0;
}
