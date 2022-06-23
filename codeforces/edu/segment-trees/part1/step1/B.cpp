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
	vector<int> mins;

	void init(int sz) {
		size = sz;
		mins = vector<int>(size * 4, INF);
	}

	void update(int pos, int val, int l, int r, int curr) {
		if(l == r)
			mins[curr] = val;
		else {
			int mid = (l + r) / 2;
			if(pos <= mid)
				update(pos, val, l, mid, 2*curr + 1);
			else
				update(pos, val, mid + 1, r, 2*curr + 2);
			mins[curr] = min(mins[2*curr + 1], mins[2*curr + 2]);
		}
	}

	void update(int pos, int val) {
		update(pos, val, 0, size - 1, 0);
	}

	int queryMin(int ql, int qr, int l, int r, int curr) {
		if(ql <= l && qr >= r)
			return mins[curr];
		if(l > qr || r < ql)
			return INF;
		int mid = (r + l) / 2;
		return min(queryMin(ql, qr, l, mid, 2*curr + 1),
					queryMin(ql, qr, mid + 1, r, 2*curr + 2));
	}

	int queryMin(int ql, int qr) {
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
    		cout << tree.queryMin(l, r - 1) << "\n";
    	}
    } 

    return 0;
}
