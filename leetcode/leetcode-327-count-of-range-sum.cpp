#include <bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<pair<int, int>> sums;
    vector<int> sums;
    pair<int, int> range;
    void init(int sz, pair<int, int>& _range) {
        size = sz;
        sums = vector<pair<int, int>>(size * 4);
        range = _range;
    }

    int query(int ql, int qr) {
        return query(ql, qr, 0, size - 1, 0);
    }
    int query(int ql, int qr, int l, int r, int node) {
        if(ql <= l && qr >= r)
            return sums[node].second;
        if(l > qr || r < ql)
            return 0;
        int mid = (l + r) / 2;
        return query(ql, qr, l, mid, 2*node + 1) +
        query(ql, qr, mid + 1, r, 2*node + 2);
    }

    void update(int pos, int val) {
        update(pos, val, 0, size - 1, 0);
    }
    void update(int pos, int val, int l, int r, int node) {
        if(l == r) {
            sums[node].first = val;
            sums[node].second = val >= range.first && val <= range.second;
        }
        else {
            int mid = (l + r) / 2;
            if(pos <= mid) {
                update(pos, val, l, mid, 2*node + 1);
            }
            else {
                update(pos, val, mid + 1, r, 2*node + 2);
             }
            sums[node].first = sums[2*node + 1].first + sums[2*node + 2];.first
            sums[node].second += sums[2*node + 1] >= range.first && sums[2*node + 1] <= range.second;
            sums[2*node + 2] <= range.second + sums[node].first >= range.first &&
            sums[node] <= range.second;
        }
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
    }
};