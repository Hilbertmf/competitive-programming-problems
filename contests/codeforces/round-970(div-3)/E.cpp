// https://codeforces.com/contest/2008/problem/E
#include <bits/stdc++.h>
using namespace std;
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

void mergeInto(int a[26], int b[26]) {
    for(int i = 0; i < 26; ++i) {
        b[i] += a[i];
    }
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = INF;

        if (n == 1) {
            cout << "1\n";
            continue;
        }
        if(n & 1) {
            
            int right[n][2][26];
            int left[n][2][26];
            
            for(int i = 0; i < n; ++i) {
                fill(right[i][0], right[i][0] + 26, 0);
                fill(right[i][1], right[i][1] + 26, 0);
                fill(left[i][0], left[i][0] + 26, 0);
                fill(left[i][1], left[i][1] + 26, 0);
            }

            // construct right
            for(int i = n - 2; i >= 0; --i) {
                if (i < n - 1) {
                    mergeInto(right[i + 1][0], right[i][0]);
                    mergeInto(right[i + 1][1], right[i][1]);
                }
                right[i][i & 1][s[i + 1] - 'a']++;
            }

            // construct left
            for(int i = 1; i < n; ++i) {
                if (i > 0) {
                    mergeInto(left[i - 1][0], left[i][0]);
                    mergeInto(left[i - 1][1], left[i][1]);
                }
                left[i][i & 1][s[i - 1] - 'a']++;
            }

            for(int i = 0; i < n; ++i) {                
                int even[26];
                int odd[26];
                fill(even, even + 26, 0);
                fill(odd, odd + 26, 0);

                // even = left[i][0] + right[i][1]
                // odd = left[i][1] + right[i][0]
                mergeInto(left[i][0], even);
                mergeInto(right[i][1], even);
                mergeInto(left[i][1], odd);
                mergeInto(right[i][0], odd);
                int sum_even = accumulate(even, even + 26, 0);
                int max_even = *max_element(even, even + 26);
                int sum_odd = accumulate(odd, odd + 26, 0);
                int max_odd = *max_element(odd, odd + 26);
                int cur = sum_odd + sum_even - max_odd - max_even;
                ans = min(ans, cur);
            }
            
            cout << ans + 1 << "\n";
        }
        else {

            int count[2][26];
            fill(count[0], count[0] + 26, 0);
            fill(count[1], count[1] + 26, 0);
            for(int i = 0; i < n; ++i)
                count[i & 1][s[i] - 'a']++;
            
            int sum_even = accumulate(count[0], count[0] + 26, 0);
            int sum_odd = accumulate(count[1], count[1] + 26, 0);
            int max_even = *max_element(count[0], count[0] + 26);
            int max_odd = *max_element(count[1], count[1] + 26);
            
            ans = sum_even + sum_odd - max_even - max_odd;            
            cout << ans << "\n";
        }
    }
    
    return 0;
}