// https://codeforces.com/contest/1999/problem/G2
#include <bits/stdc++.h>
using namespace std;
#define MID(l, r) (l + (r - l) / 2)
 
int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int response;
    cin >> response;
    return response;
}
void answer(int x) {
    cout << "! " << x << endl;
}
 
int main() {
 
    int t;
    cin >> t;
    while (t--) {
        int l = 2, r = 999, mid, res, ans;
 
        while (r - l > 2) {
            mid = MID(l, r);
 
            int sz = (r - l);
            int segment = sz / 3;
            int mid1 = l + segment;
            int mid2 = l + 2 * segment;
            res = query(mid1, mid2);
 
            // ptrs are to left of x
            if (res == mid1 * mid2) {
                l = mid2 + 1;
            }
            // ptrs are to right of x
            else if (res == (mid1 + 1) * (mid2 + 1)) {
                r = mid1;
            }
            else {
                l = mid1 + 1;
                r = mid2;
            }
        }
        ans = l;
        
        if (r - l <= 2) {
            res = query(l, l + 1);
            if (res == (l + 1) * (l + 2))
                ans = l;
            else if (res == l * (l + 2))
                ans = l + 1;
            else
                ans = l + 2;
        }
 
        answer(ans);
    }
    
    return 0;
}
