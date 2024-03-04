#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

class SegmentTreeMax {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    int build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return tree[node];
        }

        int mid = (start + end) / 2;
        int left = build(2 * node, start, mid);
        int right = build(2 * node + 1, mid + 1, end);
        return tree[node] = max(left, right);
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || left > end) // Completely outside the range
            return INT_MIN;
        if (left <= start && right >= end) // Completely inside the range
            return tree[node];

        int mid = (start + end) / 2;
        int leftQuery = query(2 * node, start, mid, left, right);
        int rightQuery = query(2 * node + 1, mid + 1, end, left, right);
        return max(leftQuery, rightQuery);
    }

public:
    SegmentTreeMax(const vector<int>& nums) {
        arr = nums;
        n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int query(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};

class SegmentTreeMin {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    int build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return tree[node];
        }

        int mid = (start + end) / 2;
        int left = build(2 * node, start, mid);
        int right = build(2 * node + 1, mid + 1, end);
        return tree[node] = min(left, right);
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || left > end) // Completely outside the range
            return INT_MAX;
        if (left <= start && right >= end) // Completely inside the range
            return tree[node];

        int mid = (start + end) / 2;
        int leftQuery = query(2 * node, start, mid, left, right);
        int rightQuery = query(2 * node + 1, mid + 1, end, left, right);
        return min(leftQuery, rightQuery);
    }

public:
    SegmentTreeMin(const vector<int>& nums) {
        arr = nums;
        n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int query(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, q;
        cin >> n;
        vector<int> nums(n);
        unordered_map<int, set<int>> indices;
        int idx = 0;
        for(auto &num : nums) {
            cin >> num;
            indices[num].insert(idx);
            idx++;
        }

        cin >> q;

		SegmentTreeMax seg_max(nums);
		SegmentTreeMin seg_min(nums);


        while (q--) {
            int l, r;
            cin >> l >> r;

            --l;
            --r;
            
            int max_N = seg_max.query(l, r);
            int min_N = seg_min.query(l, r);

            if(min_N == max_N) {
                cout << "-1 -1\n";
            }
            else {
                auto it1 = indices[min_N].lower_bound(l);
                auto it2 = indices[max_N].lower_bound(l);
				int idx1 = *it1, idx2 = *it2;
				int i = min(idx1, idx2);
				int j = max(idx1, idx2);
                cout << i + 1 << " " << j + 1 << "\n";
            }

        }
		cout << "\n";


    }
    
    return 0;
}



class Solution {
public:
	
	string frequencySort(string s) {
				
		unordered_map<char, int> char_count;
		for(char c : s) {
			char_count[c]++;
		}

		multimap<int, char, greater<int>> buckets;
		for(auto &[letter, occ] : char_count) {
			if(occ > 0)
				buckets.insert({occ, letter});
		}

		string res;
		for(auto &[occ, letter] : buckets) {
			res += string(occ, letter);
		}
		
		return res;
    }
};