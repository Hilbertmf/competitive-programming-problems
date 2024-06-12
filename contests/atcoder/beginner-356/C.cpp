#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

bool contradicts(int combination, int required_keys, vector<vector<int>>& keys_by_tests,
vector<char>& results) {

    unordered_set<int> real_keys;
    for(int i = 0; combination; ++i, combination >>= 1) {
        if (combination & 1)
            real_keys.insert(i);
    }

    for(int i = 0; i < keys_by_tests.size(); ++i) {
        // check this test
        int num_real_keys = 0;
        for(int key : keys_by_tests[i]) {
            if (real_keys.find(key) != real_keys.end())
                num_real_keys++;
        }

        bool result = false;
        if (num_real_keys >= required_keys)
            result = true;
        
        bool test_result = (results[i] == 'o') ? true : false;
    
        if (result != test_result)
            return true;
    }

    return false;
}

int32_t main() {
    FASTIO;
    
    int num_keys, tests, required_keys;
    cin >> num_keys >> tests >> required_keys;

    vector<vector<int>> keys_by_tests(tests);
    vector<char> results(tests);

    for(int t = 0; t < tests; ++t) {
        
        int inserted_keys;
        cin >> inserted_keys;
        for(int k = 0; k < inserted_keys; ++k) {
            int key;
            cin >> key;
            keys_by_tests[t].push_back(key - 1);
        }

        cin >> results[t];
    }

    int combinations = (1 << num_keys) - 1;
    int count = 0;

    while (combinations >= 0) {        
        if (!contradicts(combinations, required_keys,
                         keys_by_tests, results))
            count++;

        combinations--;
    }

    cout << count << "\n";

    return 0;
}
