// https://codeforces.com/contest/1891/problem/D
// accepted
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) ((l + r) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
const long long MOD = 1e9 + 7; // 10^9 + 7 

vector<int> powers_of_2(63);

int Logn(int x, int b) {
    if(x >= b)
        return 1 + Logn(x / b, b);
    else
        return 0;
}

int32_t main() { 
    FASTIO;

    powers_of_2[0] = 1;
    for(int i = 1; i < 63; ++i) {
        powers_of_2[i] = powers_of_2[i - 1] << 1;
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r, sum = 0;
        cin >> l >> r;
        int base_l = log2(l);
        int base_r = log2(r);

        for(int i = base_l; i < 62 && i <= base_r + 1; ++i) {
            if(i < base_l || i > base_r) continue;

                int x = powers_of_2[i];
                int y = powers_of_2[i+1] - 1;

                if(base_l == i)
                    x = l;
                if(base_r == i)
                    y = r;

                int left_g = Logn(x, i);
                int right_g = Logn(y, i);

                if(left_g == right_g) {
                    sum += (left_g * ((y - x + 1) % MOD)) % MOD;
                    sum %= MOD;
                }
                else {
                    int num_elems_left = ((long long)powl(i, (left_g + 1)) - x) % MOD;
                    int num_elems_right = (y + 1 - (long long)powl(i, right_g)) % MOD;
                    sum += (left_g * num_elems_left) % MOD;
                    sum += (right_g * num_elems_right) % MOD;
                    sum %= MOD;

                }

        }

        cout << sum << "\n";
    }

    return 0;
}