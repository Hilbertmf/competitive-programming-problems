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

        int n;
        cin >> n;
        map<int, int> count_a;
        map<int, int> count_b;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            count_a[a[i]]++;
        }
        vector<int> b(n);
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
            count_b[b[i]]++;
        }

        bool possible = true;
        bool equal = a == b;

        if (!equal) {            
            
            for(auto &[num, occ] : count_a) {
                if (count_b.find(num) == count_b.end() ||
                    count_b[num] != occ) {
                    possible = false;
                    break;
                }
            }

            // DEBUG(possible);
            
            map<int, int> idx_of_num_at_a;
            map<int, int> idx_of_num_at_b;
            for(int i = 0; i < n; ++i) {
                idx_of_num_at_a[a[i]] = i;
                idx_of_num_at_b[b[i]] = i;
            }

            map<int, int> dists;
            for(int i = 0; i < n; ++i) {
                int num = a[i];
                int j = idx_of_num_at_b[num];
                dists[num] = abs(i - j);
            }

            // if (n % 2 == 1)
            //     possible = false;
            
            // else {
                map<int, int> dist_count;
                for(auto &[k, v] : dists) {
                    dist_count[v]++;
                }

                for(auto &[dist, occ] : dist_count) {
                    if (occ % 2 != 0) {
                        possible = false;
                        break;
                    }
                }

                // for(auto &[dist, occ] : dist_count) {
                //     if (occ != 2) {
                //         possible = false;
                //         break;
                //     }
                // }


            // }

        }


        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
