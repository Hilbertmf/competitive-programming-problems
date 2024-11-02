#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;
    int t, tcase = 1;
    cin >> t;
    
    while(t--){

        int n, p;
        cin >> n >> p;
        
        long double P = p, frac, ans;
        P /= 100;
        frac = (n - 1) / (long double)n;
        ans = powl(P, frac) - P;
        cout << "Case #" << tcase << ": ";
        cout << fixed << setprecision(15);
        cout << ans * 100 << "\n";
        tcase++;
    }
    
    return 0;
}
