#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

pair<bool, bool> check(int n, int a, int b, int ans) {
    if (ans == 0 || b >= a)
        return {false, false};
    else if (a - b > 7)
        return {false, true};
    string s;
    string n_str = to_string(n);
    DEBUG(n_str);
    for(int i = 0; i < a - b; ++i) {
    DEBUG(s);
        s += n_str;
    }
    int x = stoi(s);
    if (x == ans) {
        return {true, true};
    }
    else {
        if(x > ans) {
            return {false, true};
        }
        else {
            return {false, false};
        }
    }
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;

        int a = 1, b = 1;
        int n_digits = 0;
        int curr = n;
        while (curr) {
            curr /= 10;
            n_digits++;
        }

        vector<pair<int, int>> ans;

        for(int a = 1; a <= 10000; ++a) {
            int ll = 1, rr = 10000;
            int b = MID(ll, rr);
            int org_ans = a * n - b;



            while (ll <= rr) {
                int b = MID(ll, rr);
                int org_ans = a * n - b;
                int dcm_places_org_ans = 0;
                int curr = org_ans;
                while (curr) {
                    curr /= 10;
                    dcm_places_org_ans++;
                }
                
                int dcm_places = a * (n_digits) - b;
                auto p = check(n, a, b, org_ans);
                if (dcm_places == dcm_places_org_ans &&
                    p.first) {
                    ans.push_back({a, b});
                    break;
                }
                else if (p.second) {
                    ll = b + 1;
                }
                else {
                    rr = b - 1;
                }
            }
        }

        DEBUG(ans.size());

    }
    
    return 0;
}
