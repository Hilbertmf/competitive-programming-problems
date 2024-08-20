// https://codeforces.com/contest/2001/problem/A
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, num, most_freq = 0;
        cin >> n;
        map<int, int> count;
        for(int i = 0; i < n; ++i) {
            cin >> num;
            count[num]++;
        }
        for(auto &[k, occ] : count) {
            most_freq = max(most_freq, occ);
        }

        cout << n - most_freq << "\n";
    }
    
    return 0;
}
