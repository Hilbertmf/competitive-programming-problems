#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7


class SegmentTree {
private:
    vector<int> tree;
    int n;
    int m;

    void buildTree(const vector<int>& nums, int left, int right, int index) {
        if (left == right) {
            tree[index] = nums[left] % m;
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(nums, left, mid, 2 * index + 1);
        buildTree(nums, mid + 1, right, 2 * index + 2);
        tree[index] = (tree[2 * index + 1] * tree[2 * index + 2]) % m;
    }

    int queryRangeUtil(int index, int left, int right, int qLeft, int qRight) {
        if (qLeft > right || qRight < left)
            return 1;

        if (qLeft <= left && qRight >= right)
            return tree[index];

        int mid = left + (right - left) / 2;
        int leftProduct = queryRangeUtil(2 * index + 1, left, mid, qLeft, qRight);
        int rightProduct = queryRangeUtil(2 * index + 2, mid + 1, right, qLeft, qRight);
        return (leftProduct * rightProduct) % m;
    }

public:
    SegmentTree(const vector<int>& nums, int mod) {
        n = nums.size();
        m = mod;
        tree.resize(4 * n, 1); // Initialize with 1 for product
        buildTree(nums, 0, n - 1, 0);
    }

    int queryRange(int left, int right) {
        return queryRangeUtil(0, 0, n - 1, left, right);
    }
};

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        string s;
        cin >> s;

        SegmentTree segTree(nums, m);

        int left = 0, right = n - 1;
        for(int i = 0; i < s.size(); ++i) {
            cout << segTree.queryRange(left, right) << " ";
            if(s[i] == 'L') {
                left++;
            }
            else {
                right--;
            }
        }

        cout << "\n";
    }
    
    return 0;
}
