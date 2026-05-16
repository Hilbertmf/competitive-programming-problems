#include <bits/stdc++.h>
using namespace std;



int main() {

    


    return 0;
}


/*


5 2 6 1

1 6

*/


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

// IMPORTANT!! (for using less_equals<K>)
// using less_equals<K> makes lower_bound work as upper_bound and vice-versa
// for erase use: any.erase(any.find_by_order(any.order_of_key(val)));
// don't use .find() because it will always return .end()
template <typename Key, typename Val, typename Comp = less_equal<Key>>
using indexed_multimap = indexed_map<Key, Val, Comp>;

template <typename Key, typename Comp = less_equal<Key>>
using indexed_multiset = indexed_map<Key, null_type, Comp>;

bool contains(indexed_multiset<int>& tree, int val) {
    int order = tree.order_of_key(val);
    return 0 <= order && order < tree.size() &&
           *tree.find_by_order(order) == val;
}

bool contains(indexed_multimap<int, int>& tree, int val) {
    int order = tree.order_of_key(val);
    return 0 <= order && order < tree.size() &&
           tree.find_by_order(order)->first == val;
}

typedef tree<int, // key type
null_type, // mapped-policy
less_equal<int>, // key comparison function
rb_tree_tag, // underlying data structure
tree_order_statistics_node_update>
ordered_set;
// use order_of_key and find_by_order methods
// using less_equal exchanges upper and lower bounds
// use upper bound to erase elements
// order_of_key refers to the first occurence of key

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set m;
        int count = 0;
        for(int i = nums.size() - 1; i >= 0; --i) {
            long long cur = nums[i], target;
            target = cur - 1;
            if (cur % 2 == 0)
                target--;
            target /= 2;
            target++;
            count += m.order_of_key(target);

            m.insert(cur);
        }

        return count;
    }
};