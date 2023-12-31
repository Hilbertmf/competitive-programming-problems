// https://codeforces.com/contest/1916/problem/B
// accepted
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int minPrime(int n) {
    if(n % 2 == 0) return 2;
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0)
            return i;
    }
    return n;
}

bool coprime(int a, int b) {
    return __gcd(a, b) == 1;
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int a, b;
        cin >> a >> b;

        if(a == 1) {
            cout << b * b << "\n";
        }
        else if(coprime(a, b)) {
            cout << a * b << "\n";
        }
        else {
            cout << b * min(minPrime(b), minPrime(a)) << "\n";
        }

    }
    
    return 0;
}
