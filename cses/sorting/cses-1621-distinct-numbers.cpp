// https://cses.fi/problemset/task/1621
// time: O(n)
// space: O(n)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;
    
    int n;
    cin >> n;
    vector<int> nums(n);
    int num;
    unordered_map<int, int> count;
    count.reserve(n);
    for(int i = 0; i < n; ++i) {
        cin >> num;
        count[num]++;
    }
    cout << count.size() << "\n";

    return 0;
}
