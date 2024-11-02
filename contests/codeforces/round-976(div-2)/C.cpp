// https://codeforces.com/contest/2020/problem/C
// AC
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

string decToBinaryRev(int n) {
    int cur = n;
    string s;
    while (cur) {
        if (cur & 1) s += '1';
        else s += '0';
        cur >>= 1;
    }
    return s;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int b, c, d;
        cin >> b >> c >> d;

        string b_bits, c_bits, d_bits, a_bits;
        b_bits = decToBinaryRev(b);
        c_bits = decToBinaryRev(c);
        d_bits = decToBinaryRev(d);

        // make their size equal pushing left zeros
        int sz = max({b_bits.size(), c_bits.size(), d_bits.size()});
        while (b_bits.size() < sz) b_bits += '0';
        while (c_bits.size() < sz) c_bits += '0';
        while (d_bits.size() < sz) d_bits += '0';
        reverse(b_bits.begin(), b_bits.end());
        reverse(c_bits.begin(), c_bits.end());
        reverse(d_bits.begin(), d_bits.end());

        bool possible = true;
        for(int i = 0; i < c_bits.size() && possible; ++i) {
            if (b_bits[i] == '0' && c_bits[i] == '0')
                a_bits += d_bits[i];
            else if (b_bits[i] == '1' && c_bits[i] == '1')
                a_bits += (char)((1 - (int)(d_bits[i] - '0')) + '0');
            else if (b_bits[i] == '1' && c_bits[i] == '0') {
                // d[i] MUST BE 1
                if (d_bits[i] != '1')
                    possible = false;
                else
                    a_bits += '0';
            }
            else {
                // d[i] MUST BE 0
                if (d_bits[i] != '0')
                    possible = false;
                else
                    a_bits += '0';
            }
        }

        if(possible) {
            // get a from a_bits
            long long a = 0;
            for(int i = a_bits.size() - 1, p = 0; i >= 0; --i, ++p) {
                if (a_bits[i] == '1') {
                    a += (1ll << p);
                }
            }
            cout << a << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    
    return 0;
}
