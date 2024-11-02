#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7


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

// IMPORTANT!! (for using less_equals<K>)
// using less_equals<K> makes lower_bound work as upper_bound and vice-versa
// for erase use: any.erase(any.find_by_order(any.order_of_key(val)));
// don't use .find() because it will always return .end()


int main() {
    FASTIO;

    int rows, cols, q, r, c, row, col;
    cin >> rows >> cols;

    indexed_set<int> walls_row[rows];
    indexed_set<int> walls_col[cols];

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            walls_row[i].insert(j);
        }
    }
    for(int i = 0; i < cols; ++i) {
        for(int j = 0; j < rows; ++j) {
            walls_col[i].insert(j);
        }
    }
    cin >> q;

    int count = rows * cols;

    while (q--) {
        cin >> r >> c;
        --r; --c;

        // check if theres a wall at r,c
        if (walls_row[r].find(c) != walls_row[r].end()) {
            walls_row[r].erase(walls_row[r].find(c));
            walls_col[c].erase(walls_col[c].find(r));
            count--;
        }
        else {

            // right
            auto it_end = walls_row[r].upper_bound(c);

            bool delete_right = it_end != walls_row[r].end();
            bool delete_left = it_end != walls_row[r].begin();
            if (delete_right) {
                col = *it_end;
                walls_col[col].erase(r);
                count--;
            }

            if (delete_left) {
                auto it_beg = prev(it_end);
                col = *it_beg;
                walls_row[r].erase(it_beg);
                walls_col[col].erase(r);
                count--;
            }

            if (delete_right)
                walls_row[r].erase(it_end);

            auto it_end2 = walls_col[c].upper_bound(r);
            bool delete_down = it_end2 != walls_col[c].end();
            bool delete_up = it_end2 != walls_col[c].begin();
            int up;
            if (delete_down) {
                row = *it_end2;
                walls_row[row].erase(c);
                count--;
            }

            if (delete_up) {
                auto it_beg2 = prev(it_end2);
                row = *it_beg2;
                walls_col[c].erase(it_beg2);
                walls_row[row].erase(c);
                count--;
            }

            if (delete_down)
                walls_col[c].erase(it_end2);

        }
    }
    cout << count << "\n";

    return 0;
}
