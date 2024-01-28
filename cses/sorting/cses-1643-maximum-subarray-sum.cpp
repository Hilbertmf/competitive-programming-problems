// time: O(n)
// space: O(1)
#include <bits/stdc++.h>
using namespace std;
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

int main() {
    FASTIO;

    int n;
    cin >> n;
    
    long long max_sum = -INF, sum = 0;
    long long max_elem = -INF;
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        max_elem = max(max_elem, (long long)num);
        if(sum + num < 0)
            sum = 0;
        else
            sum += num;
        
        if(sum > 0)
            max_sum = max(max_sum, sum);
    }

    cout << max(max_sum, max_elem) << "\n";

    return 0;
}
