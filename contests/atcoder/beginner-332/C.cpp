// accepted
// https://atcoder.jp/contests/abc332/tasks/abc332_c
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

void storeAndReset(int& m, int& l, int& stored_plain_shirts, int& stored_logo_shirts,
int& plain_shirts, int& logo_shirts) {
    stored_plain_shirts = m + plain_shirts;
    stored_logo_shirts = l + logo_shirts;
    m = stored_plain_shirts;
    l = stored_logo_shirts;
    plain_shirts = 0;
    logo_shirts = 0;    
}

int32_t main() {
    FASTIO;

    int m, n;
    string s;
    cin >> n >> m >> s;

    int init = m;    
    int stored_logo_shirts = 0;
    int logo_shirts = 0;
    int stored_plain_shirts = m;
    int plain_shirts = 0;
    int l = 0;


    for(int i = 0; i < s.size(); ++i) {
        while (i < s.size()) {
            if(s[i] == '1') {
                if(stored_plain_shirts > 0) {
                    stored_plain_shirts--;
                }
                else if(stored_logo_shirts > 0) {
                    stored_logo_shirts--;
                }
                else {
                    logo_shirts++;
                }
            }
            else if(s[i] == '2') {
                if(stored_logo_shirts > 0) {
                    stored_logo_shirts--;
                }
                else {
                    logo_shirts++;
                }
            }
            else if(s[i] == '0') {
                storeAndReset(m, l, stored_plain_shirts, stored_logo_shirts,
                plain_shirts, logo_shirts);
                
                break;
            }
            i++;
        }

    }
    storeAndReset(m, l, stored_plain_shirts, stored_logo_shirts,
    plain_shirts, logo_shirts);
    
    cout << m + l - init << "\n";

    return 0;
}
