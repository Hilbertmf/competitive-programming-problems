// TODO
// https://cses.fi/problemset/task/1712
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

long long power(long long a, long long b, int mod) {
    if(b == 0) return 1;
    if(b == 1) return a;

    long long res = power(a, b / 2, mod) % mod;
    res = (res * res) % mod;
    if(b % 2 == 1)
        res *= a;
    return res % mod;
}

int main() {
    FASTIO;
    int queries;
    cin >> queries;
    
    while(queries--){

        long long a, b, c;
        cin >> a >> b >> c;
        int tmp = power(b, c, a) % a;
        cout << power(a, tmp, MOD) % MOD << "\n";

    }
    
    return 0;
}
