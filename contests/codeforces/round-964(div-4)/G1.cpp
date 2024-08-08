// https://codeforces.com/contest/1999/problem/G1
#include <bits/stdc++.h>
using namespace std;
#define MID(l, r) (l + (r - l) / 2)
#define int long long

void query(int a, int b) {
    cout << "? " << a << " " << b << endl;
}

int32_t main() {

    int t;
    cin >> t;
    while (t--) {
        int l = 2, r = 999, mid, res;

        while (l <= r) {
            mid = MID(l, r);
            query(mid, mid + 1);
            cin >> res;
            if (res == mid * (mid + 2)) {
                mid++;
                break;
            }
            else if (res == mid * (mid + 1))
                l = mid + 1;
            else
                r = mid - 1;
        }

        cout << "! " << mid << endl;
    }
    
    return 0;
}
