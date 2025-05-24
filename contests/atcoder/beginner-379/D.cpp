// https://atcoder.jp/contests/abc379/tasks/abc379_d
// AC
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

struct VeniceSet {
	multiset<int> S;
	int water_level = 0;
	void add(int v) {
		S.insert(v + water_level);
	}
	void remove(int v) {
		S.erase(S.find(v + water_level));
	}
	void updateAll(int v) {
		water_level += v;
	}
	int getMin() {
		return *S.begin() - water_level;
	}
	int getMax() {
		return *S.rbegin() - water_level;
	}
	int size() {
		return S.size();
	}
};

int32_t main() {
    FASTIO;

    int q;
    VeniceSet mySet;
    cin >> q;    
    while (q--) {
        int type, t, h;
        cin >> type;

        if(type == 1) {
            mySet.add(0);
        }
        else if (type == 2) {
            cin >> t;
            mySet.updateAll(t * -1);
        }
        else {
            cin >> h;
            int out = 0;
            while (mySet.size() > 0 && mySet.getMax() >= h) {
                int top = mySet.getMax();
                mySet.remove(top);
                out++;
            }
            cout << out << "\n";
        }
    }

    return 0;
}
