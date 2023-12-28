#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

bool possibleTank(int h, vector<int>& heights, int water) {
    int n = heights.size();
    vector<int> prefix_complement(n);
    if(heights[0] > h) {
        prefix_complement[0] = 0;
    }
    else {
        prefix_complement[0] = h - heights[0];
    }

    for(int i = 1; i < n; ++i) {
        prefix_complement[i] = prefix_complement[i - 1];
        if(heights[i] < h)
            prefix_complement[i] += h - heights[i];
        if(prefix_complement[i] > water)
            return false;
    }
    
    return true;
}

int maxHeightSearch(int l, int r, vector<int>& heights, int water) {
    if(possibleTank(r, heights, water))
        return r;
    
    int mid = MID(l, r);

    while (l <= r) {
        bool possible = possibleTank(mid, heights, water);
        bool possible_nxt = possibleTank(mid + 1, heights, water);
        if(possible && !possible_nxt) {
            return mid;
        }
        else if(!possible) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
        mid = MID(l, r);
    }
    return -1;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, water;
        cin >> n >> water;
        vector<int> heights(n);
        for(int &h : heights) cin >> h;
        
        int min_h = 1;
        int max_h = *max_element(heights.begin(), heights.end()) + ceil(water / (double)n);

        cout << maxHeightSearch(min_h, max_h, heights, water) << "\n";
    }
    
    return 0;
}
