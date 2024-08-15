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
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            freq[a[i]]++;
        }
        cin >> m;
        vector<string> strs(m);
        for(int i = 0; i < m; ++i) {
            cin >> strs[i];
        }

        vector<int> freq_vec;
        for(auto &[k, v] : freq) {
            freq_vec.push_back(v);
        }

        
        if (freq.size() <= 26) {
            int idx = 0;
            map<int, int> mapping;
            for(int i = 0; i < n; ++i) {
                if (mapping.find(a[i]) == mapping.end()) {
                mapping[a[i]] = idx;
                ++idx;
                }
            }
            for(int i = 0; i < n; ++i) {
                a[i] = mapping[a[i]];
            }
        }

        freq_vec.resize(26);
        sort(freq_vec.begin(), freq_vec.end());


        for(int i = 0; i < m; ++i) {
            bool pos = true;

            if (freq.size() > 26 || strs[i].size() != n)
                pos = false;
            
            else {
                string curr = strs[i];
                vector<int> b(n);

                int idx = 0;
                map<char, int> mapping;
                for(int i = 0; i < n; ++i) {
                    if (mapping.find(curr[i]) == mapping.end()) {
                        mapping[curr[i]] = idx;
                        ++idx;
                    }
                }
                for(int i = 0; i < n; ++i) {
                    b[i] = mapping[curr[i]];
                }

                if (a != b) pos = false;
            }

            if(pos) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }

        
    }
    
    return 0;
}
