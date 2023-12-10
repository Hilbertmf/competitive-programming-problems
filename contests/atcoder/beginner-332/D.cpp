// incomplete: only calculates if its possible or not to 
// transform one grid into another
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

    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    vector<vector<int>> b(r, vector<int>(c));

    multiset<int> set_a;
    multiset<int> set_b;

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> a[i][j];
            set_a.insert(a[i][j]);
        }
    }

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> b[i][j];
            set_b.insert(a[i][j]);
        }
    }

    bool pos = set_a == set_b;


    if(!pos) {
        cout << -1 << "\n";
        return 0;
    }

    else {

        multimap<int, vector<int>> a_pos;
        multiset<vector<int>> b_pos;
        vector<multiset<int>> line_a(r);
        vector<multiset<int>> col_a(c);
        vector<multiset<int>> line_b(r);
        vector<multiset<int>> col_b(c);
        
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                a_pos.insert({a[i][j], {i, j}});
                line_a[i].insert(a[i][j]);
                col_a[j].insert(a[i][j]);
            }
        }
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                line_b[i].insert(b[i][j]);
                col_b[j].insert(b[i][j]);
            }
        }


        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                
                int n = a_pos.count(b[i][j]);
                int count = 0;

                bool found = false;
                for(auto it = a_pos.find(b[i][j]); it != a_pos.end() && count < n; ++it, ++count) {
                    int i1 = it->second[0];
                    int j1 = it->second[1];

                    if(line_a[i] == line_b[i1] && col_a[j] == col_b[j1]) {
                        found = true;
                        a_pos.erase(it);
                        break;
                    }
                }

                if(!found) {
                    cout << -1 << "\n";
                    return 0;
                }

            }
        }


        pos = true;
        
        // TODO: count min num of operations
    }


    return 0;
}
