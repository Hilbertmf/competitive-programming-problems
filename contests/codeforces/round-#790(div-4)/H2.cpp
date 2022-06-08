// https://codeforces.com/contest/1676/problem/H2
#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<
long long, // key type
null_type, // mapped-policy
less_equal<long long>, // key comparison function
rb_tree_tag, // underlying data structure
tree_order_statistics_node_update>
ordered_multiset;
// using less_equal exchanges upper and lower bounds
// use upper bound to erase elements
// also order_of_key refers to the first occurence of key

#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

int main() {    

    int t;
    cin >> t;
    while (t--) {
        int length;
        cin >> length;
        vector<long long> segments(length);
        for(int i = 0; i < length; ++i) cin >> segments[i];
        
        long long numCrossings = 0;
        ordered_multiset indexedMultiset;

        for(int i = length - 1; i >= 0; --i) {
            indexedMultiset.insert(segments[i]);
            // idx of last elem in set
            int crossings = indexedMultiset.order_of_key(segments[i] + 1) - 1;
            numCrossings += crossings;
        }

        cout << numCrossings << "\n";

    }

    return 0;
}