#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF INT_MAX 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const long long MOD = 1000000007; // 10^9 - 7 

struct segtree{
    int size;
    vector<pair<int, int>> mins;

    void init(int sz) {
        size = sz;
        mins = vector<pair<int, int>>(size * 4, {INF, 1});
    }

    void update(int pos, int val, int l, int r, int curr) {
        if(l == r)
            mins[curr] = {val, 1};
        else {
            int mid = (l + r) / 2;
            if(pos <= mid)
                update(pos, val, l, mid, 2*curr + 1);
            else
                update(pos, val, mid + 1, r, 2*curr + 2);
            auto pLeft = mins[2*curr + 1];
            auto pRight = mins[2*curr + 2];
            if(pLeft.first == pRight.first && pLeft.first != INF)
                mins[curr] = {pLeft.first, pLeft.second + pRight.second};
            else {
                if(pLeft.first < pRight.first)
                    mins[curr] = pLeft;
                else
                    mins[curr] = pRight;
            }
        }
    }

    void update(int pos, int val) {
        update(pos, val, 0, size - 1, 0);
    }

    pair<int, int> queryMin(int ql, int qr, int l, int r, int curr) {
        if(ql <= l && qr >= r)
            return mins[curr];
        if(l > qr || r < ql)
            return {INF, 1};
        int mid = (r + l) / 2;
        auto pLeft = queryMin(ql, qr, l, mid, 2*curr + 1);
        auto pRight = queryMin(ql, qr, mid + 1, r, 2*curr + 2);
        if(pLeft.first == pRight.first && pLeft.first != INF)
            return {pLeft.first, pLeft.second + pRight.second};
        else {
            if(pLeft.first < pRight.first)
                return pLeft;
            else
                return pRight;
        }
    }

    pair<int, int> queryMin(int ql, int qr) {
        return queryMin(ql, qr, 0, size - 1, 0);
    }

};


int main() { 
    FASTIO;
    int n, m;
    cin >> n >> m;
    segtree tree;
    tree.init(n);
    int num;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        tree.update(i, num);
    }

    while(m-- ) {
        int op;
        cin >> op;
        if(op == 1) {
            int pos, val;
            cin >> pos >> val;
            tree.update(pos, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            auto p = tree.queryMin(l, r - 1);
            cout << p.first << " " << p.second << "\n";
        }
    } 

    return 0;
}
