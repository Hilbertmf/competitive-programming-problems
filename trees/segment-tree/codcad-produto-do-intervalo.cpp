// accepted
// https://neps.academy/br/course/estruturas-de-dados-(codcad)/lesson/produto-do-intervalo
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

struct segtree {
    int size;
    vector<int> prods;

    void init(int sz) {
        size = sz;
        prods = vector<int>(size * 4, 1);
    }

    void update(int pos, int val, int l, int r, int node) {
        if(l == r)
            prods[node] = val;
        else {
            int mid = (l + r) / 2;
            if(pos <= mid)
                update(pos, val, l, mid, 2*node + 1);
            else
                update(pos, val, mid + 1, r, 2*node + 2);
            prods[node] = prods[2*node + 1] * prods[2*node + 2];
        }
    }

    void update(int pos, int val) {
        update(pos, val, 0, size - 1, 0);
    }

    int query(int ql, int qr) {
        return query(ql, qr, 0, size - 1, 0);
    }

    int query(int ql, int qr, int l, int r, int node) {
        if(ql <= l && qr >= r)
            return prods[node];
        if(l > qr || r < ql)
            return 1;
        int mid = (l + r) / 2;
        return query(ql, qr, l, mid, 2*node + 1) *
                query(ql, qr, mid + 1, r, 2*node + 2);
    }
};

int main() { 
    FASTIO;

    int numElems, numRounds;

    while(cin >> numElems) {
        cin >> numRounds;

        segtree tree;
        tree.init(numElems);
        int num = 1;
        string res;

        for(int i = 0; i < numElems; ++i) {
            cin >> num;
            if(num >= 1) num = 1;
            else if(num == 0) num = 0;
            else if(num < 0) num = -1;
            tree.update(i, num);
        }

        while(numRounds--) {
            char operation;
            cin >> operation;

            if(operation == 'C') {
                int pos, val;
                cin >> pos >> val;
                --pos;
                if(val >= 1) val = 1;
                else if(val == 0) val = 0;
                else if(val < 0) val = -1;
                
                tree.update(pos, val);
            }
            else {
                int l, r;
                cin >> l >> r;
                --l;
                --r;
                int prod = tree.query(l, r);
                if(prod > 0) res += '+';
                else if(prod == 0) res += '0';
                else res += '-';
            }
        }

        cout << res << "\n";
    }
    
    return 0; 
}
