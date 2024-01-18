// https://cses.fi/problemset/task/1068
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;

    long long n;
    cin >> n;

    while (n != 1) {
        cout << n << " ";
        if(n % 2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            n++;
        }
    }

    cout << 1 << "\n";

    return 0;
}
