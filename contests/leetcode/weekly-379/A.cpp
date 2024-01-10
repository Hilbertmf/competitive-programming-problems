
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        double ans = 0;
        for(int i = 0; i < dimensions.size(); ++i) {
            int diag_sq = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
            double diag = sqrt(diag_sq);
            ans = max(ans, diag);
        }

        int area = 0;
        for(int i = 0; i < dimensions.size(); ++i) {
            int diag_sq = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
            double diag = sqrt(diag_sq);
            if(diag == ans) {
                area = max(area, dimensions[i][0] * dimensions[i][1]);
            }
        }

        return area;
    }
};
