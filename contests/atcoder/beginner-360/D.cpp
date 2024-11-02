#include <bits/stdc++.h>
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
// #define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// _GLIBCXX_DEBUG must not be defined otherwise some internal check will fail
#undef _GLIBCXX_DEBUG

template <typename Key, typename Val, typename Comp = less<Key>>
using indexed_map = tree<Key, // key type
                         Val, // val type
                        Comp, // comparison function
                       rb_tree_tag, tree_order_statistics_node_update>;

template <typename Key, typename Comp = less<Key>>
using indexed_set = indexed_map<Key, null_type, Comp>;

int main() {
    FASTIO;
    int n, t;
    string s;
    cin >> n >> t >> s;

    vector<long long> x(n);
    indexed_set<long long> tree;
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
        if (s[i] == '0')
            tree.insert(x[i]);
    }

    long long count = 0ll;

    for(int i = n - 1; i >= 0; --i) {        
        if (s[i] == '1') {
            long long start = tree.order_of_key(x[i] + 1);
            long long end = tree.order_of_key((x[i] + (2ll * t) + 1));
            count += end - start;
        }
    }

    cout << count << "\n";

    return 0;
}
