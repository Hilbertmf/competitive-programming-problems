class Solution {
public:
    struct state {
        long long val;
        int idx;
        bool shouldInsert;
    };

    struct segtree {
        int size;
        vector<int> sums;

        void init(int sz) {
            size = sz;
            sums = vector<int>(size * 4);
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
            if(l == r)
                sums[node] = val;
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

    int reversePairs(vector<int>& nums) {
        vector<state> states;
        segtree tree;
        tree.init(nums.size());
        int ans = 0;
        vector<long long> longNums(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            states.push_back((state){longNums[i] * 2, i, false});
            states.push_back((state){longNums[i], i, true});
        }

        sort(states.begin(), states.end(),
        [](state& lhs, state& rhs) {
            if(lhs.val == rhs.val)
                return lhs.idx > rhs.idx;
            return lhs.val > rhs.val;
        });

        for(auto &elem : states) {
            int idx = elem.idx;
            int val = elem.val;
            if(elem.shouldInsert)
                tree.update(idx, 1);
            else if(idx == 0)
                continue;
            else
                ans += tree.query(0, idx - 1);
        }

        return ans; 
    }
};
