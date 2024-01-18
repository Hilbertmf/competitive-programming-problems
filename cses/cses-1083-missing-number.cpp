// https://cses.fi/problemset/task/1083
// time: O(1)
// space: O(1)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;

    int n;
    cin >> n;
    long long sum = 0;
    int num;
    for(int i = 0; i < n - 1; ++i) {
        cin >> num;
        sum += num;
    }
    // arithmetic sequence
    long long total_sum = (long long)n * (n + 1) / 2;
    int missing = total_sum - sum;
    cout << missing << "\n";

    return 0;
}
