// https://codeforces.com/contest/1999/problem/B
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

bool check(pair<int, int>& p1, pair<int, int>& p2) {
    return (p1.first > p2.first && p1.second >= p2.second) ||
           (p1.first >= p2.first && p1.second > p2.second);
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int a1, a2, b1, b2, count = 0;
        pair<int, int> p1, p2;
        cin >> a1 >> a2 >> b1 >> b2;

        p1 = {a1, a2}, p2 = {b1, b2};
        if (check(p1, p2)) count++;

        p1 = {a2, a1}, p2 = {b1, b2};
        if (check(p1, p2)) count++;

        p1 = {a1, a2}, p2 = {b2, b1};
        if (check(p1, p2)) count++;

        p1 = {a2, a1}, p2 = {b2, b1};
        if (check(p1, p2)) count++;
        cout << count << "\n";
    }
    
    return 0;
}
