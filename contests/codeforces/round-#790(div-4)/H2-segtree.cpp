// accepted
// https://codeforces.com/contest/1676/problem/H2
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

struct segtree{
    int size;
    vector<int> sums;

    void init(int sz) {
        size = sz;
        sums = vector<int>(size*4);
    }

    int query(int ql, int qr) {
        return query(ql, qr, 0, size - 1, 0);
    }

    int query(int ql, int qr, int l, int r, int node) {
        if(ql <= l && qr >= r)
            return sums[node];
        if(r < ql || l > qr)
            return 0;
        int mid = (l + r) / 2;
        return query(ql, qr, l, mid, 2*node + 1) +
            query(ql, qr, mid + 1, r, 2*node + 2);
    }

    void update(int pos, int val) {
        update(pos, val, 0, size - 1, 0);
    }

    void update(int pos, int val, int l, int r, int node) {
        if(l == r) sums[node] = val;
        else {
            int mid = (l + r) / 2;
            if(pos <= mid) {
                update(pos, val, l, mid, 2*node + 1);
            }
            else {
                update(pos, val, mid + 1, r, 2*node + 2);
            }
            sums[node] = sums[2*node + 1] + sums[2*node + 2];
        }
    }

};


int main() {    

    int t;
    cin >> t;
    while (t--) {
        int length;
        cin >> length;
        vector<long long> segments(length);
        vector<pair<int, int>> aux(length);
        for(int i = 0; i < length; ++i) {
            cin >> segments[i];
            aux[i] = {segments[i], i};
        }
        segtree tree;
        tree.init(length);
        sort(aux.begin(), aux.end(),
        [](pair<int, int>& lhs, pair<int, int>& rhs) {
            if(lhs.first == rhs.first)
                return lhs.second > rhs.second;
            return lhs.first < rhs.first;
        });
        
        long long numCrossings = 0;

        for(int i = 0; i < length; ++i) {
            int idx = aux[i].second;
            numCrossings += tree.query(idx, length - 1);
            tree.update(idx, 1);
        }
        
        cout << numCrossings << "\n";

    }

    return 0;
}