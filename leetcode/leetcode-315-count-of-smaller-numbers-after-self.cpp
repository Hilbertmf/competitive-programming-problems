#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size());        
        vector<pair<int, int>> aux(nums.size());
        for(int i = 0; i < nums.size(); ++i) aux[i] = {nums[i], i};
        sort(aux.begin(), aux.end());
        segtree tree;
        tree.init(nums.size());

        for(int i = 0; i < nums.size(); ++i) {
            int idx = aux[i].second;
            counts[idx] = tree.query(idx, nums.size() - 1);
            tree.update(idx, 1);
        }

        return counts;
    }
};