#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

/*
create an array that will be the remainder of each number with gcd(a, b)
ans will be the range of this array
then try to add g to each element and see if this results in a better answer
*/

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){
        
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        int g = __gcd(a, b);

        vector<int> mods;
        for(auto &num : arr) {
            mods.push_back(num % g);
        }

        sort(mods.begin(), mods.end());
        mods.erase(unique(mods.begin(), mods.end()), mods.end());
        int MIN = mods[0];
        int MAX = mods.back();
        int range = MAX - MIN;

        if (mods.size() > 1 && mods[0] + g > MAX) {
            set<int> m(mods.begin(), mods.end());
            while (m.size() > 1) {
                int top = *m.begin();
                top += g;
                m.erase(m.begin());
                MAX = max(top, *m.rbegin());
                MIN = *m.begin();
                range = min(range, MAX - MIN);
            }
        }

        cout << range << "\n";
    }
    
    return 0;
}
