// https://cses.fi/problemset/task/1095
// time: O(log(b))
// space: O(log(b))
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

long long power(long long a, long long b) {
    if(b == 0) return 1;
    if(b == 1) return a;

    long long res = power(a, b / 2) % MOD;
    res = (res * res) % MOD;
    if(b % 2 == 1)
        res *= a;
    return res % MOD;
}

int main() {
    FASTIO;
    int queries;
    cin >> queries;
    
    while(queries--){

        long long a, b;
        cin >> a >> b;
        cout << power(a, b) % MOD << "\n";

    }
    
    return 0;
}
