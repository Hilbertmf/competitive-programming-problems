#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        
        double n, k;
        cin >> n >> k;
        int ans;
        int sum;
        if (n > k) {
            sum = k * ceil(n / k);
            ans = ceil(sum / n);
        }
        else if (k > n) {
            ans = ceil(k / n);
        }
        else
            ans = 1;

        cout << ans << "\n";
    }

    return 0;
}
