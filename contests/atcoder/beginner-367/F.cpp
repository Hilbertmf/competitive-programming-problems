#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define int long long
const long long MOD = 1e9 + 9;

map<int, int> tab;

int inv(int a) {
  return a <= 1 ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}
int sum(int l, int r, vector<int>& prefix) {
    int res = prefix[r];
    if (l > 0) res = (res - prefix[l - 1] + MOD) % MOD;
    return res;
}

int prod(int l, int r, vector<int>& prefix) {
    int res = prefix[r];
    if (l > 0) res = (res * inv(prefix[l - 1])) % MOD;    
    return res;
}

void init(vector<int>& p_sum, vector<int>& p_prod, vector<int>& a) {
    p_sum[0] = a[0] % MOD;
    p_prod[0] = a[0] % MOD;
    for(int i = 1; i < a.size(); ++i) {
        p_sum[i] = (a[i] + p_sum[i - 1]) % MOD;
        p_prod[i] = (a[i] * p_prod[i - 1]) % MOD;
    }
}

int32_t main() {
    FASTIO;
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    set<int> nums;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
        nums.insert(b[i]);
    }

    for(auto &num : nums) {
        tab[num] = rand();
    }

    for(int i = 0; i < n; ++i) {
        a[i] = tab[a[i]];
        b[i] = tab[b[i]];
    }

    vector<int> p_sum_a(n), p_sum_b(n);
    vector<int> p_prod_a(n), p_prod_b(n);
    init(p_sum_a, p_prod_a, a);
    init(p_sum_b, p_prod_b, b);
    
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--; r1--; l2--; r2--;

        bool pos = (r1 - l1 + 1) == (r2 - l2 + 1);
        
        if (pos) {
            if (!(sum(l1, r1, p_sum_a) == sum(l2, r2, p_sum_b) &&
                prod(l1, r1, p_prod_a) == prod(l2, r2, p_prod_b)))
                pos = false;
        }

        if(pos) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    
    return 0;
}
