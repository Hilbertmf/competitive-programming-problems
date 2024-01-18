// https://cses.fi/problemset/task/1094/
// time: O(n)
// space: O(1)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;

    int n;
    cin >> n;
    int curr, prev = 0;
    long long moves = 0;

    for(int i = 0; i < n; ++i) {
        cin >> curr;
        if(prev > curr)
            moves += (long long)prev - curr;

        prev = max(curr, prev);
    }

    cout << moves << "\n";
    return 0;
}
