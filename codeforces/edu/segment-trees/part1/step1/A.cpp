// accepted
// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
#include <bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<long long> sums;

    void init(int _size) {
        size = _size;
        sums = vector<long long>(size * 4);
    }

    long long querySum(int queryLeft, int queryRight, int node, int left, int right) {
        // totally inside
        if(queryLeft <= left && queryRight >= right)
            return sums[node];
        // totally outside
        if(left > queryRight || right < queryLeft)
            return 0;
        // partially
        int mid = (left + right) / 2;
        return querySum(queryLeft, queryRight, 2 * node + 1, left, mid) +
                querySum(queryLeft, queryRight, 2 * node + 2, mid + 1, right);
    }

    long long querySum(int queryLeft, int queryRight) {
        return querySum(queryLeft, queryRight, 0, 0, size - 1);
    }

    void update(int pos, int val, int node, int left, int right) {
        // leaf
        if(left == right)
            sums[node] = val;
        else {
            int mid = (left + right) / 2;
            if(pos <= mid)
                update(pos, val, 2 * node + 1, left, mid);
            else
                update(pos, val, 2 * node + 2, mid + 1, right);
            // update ancestrals
            sums[node] = sums[2*node + 1] + sums[2*node + 2];
        }
    }
    
    void update(int pos, int val) {
        update(pos, val, 0, 0, size - 1);
    }
};


int main() {

    int n, m;
    cin >> n >> m;

    segtree tree;
    tree.init(n);
    int num = 0;

    for(int i = 0; i < n; ++i) {
        cin >> num;
        tree.update(i, num);
    }
    
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) { // update
            int pos, val;
            cin >> pos >> val;
            tree.update(pos, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << tree.querySum(l, r - 1) << "\n";
        }
    }

    return 0;
}