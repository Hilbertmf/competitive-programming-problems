#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;

    string s;
    cin >> s;
    int i = 0;
    for(i = s.size() - 1; i >= 0; --i) {
        if(s[i] == '.') break;
    }

    cout << s.substr(i + 1) << "\n";
    return 0;
}


class Solution {
public:
    bool findPointsBetween(int x1, int x2, int y1, int y2,
    int ignore1, int ignore2, vector<vector<int>>& points) {
        vector<int> ys {y1, y2};
        sort(ys.begin(), ys.end());
        y1 = ys[0], y2 = ys[1];
        vector<int> xs {x1, x2};
        sort(xs.begin(), xs.end());
        x1 = xs[0], x2 = xs[1];
        
        for(int i = 0; i < points.size(); ++i) {
            if(i == ignore1 || i == ignore2)
                continue;

            int x = points[i][0];
            int y = points[i][1];

            if(y1 == y2) {
                if(x1 <= x && x <= x2)
                    return true;
            }
            else if (x1 == x2){
                if(y1 <= y && y <= y2)
                    return true;
            }

            else {
                if(x1 <= x && x <= x2 &&
                y1 <= y && y <= y2)
                    return true;
            }
        }

        return false;
    }

    bool chisatoHappy(int p1, int p2, vector<vector<int>>& points) {
        vector<int> person1 = points[p1];
        vector<int> person2 = points[p2];
        int x1 = person1[0];
        int x2 = person2[0];
        int y1 = person1[1];
        int y2 = person2[1];
        // check chisato left upper & takina lower right:
        // same line
        if(x1 == x2) {
            if(y1 < y2)
                return false;
        }
        // same col
        else if(y1 == y2){
            if(x1 > x2)
                return false;
        }
        else {
            if(x1 > x2 || y1 < y2)
                return false;
        }

        // check if another point inside square
        int ignore1 = p1, ignore2 = p2;
        if(findPointsBetween(x1, x2, y1, y2, ignore1, ignore2, points))
            return false;
        else
            return true;

    }

    int numberOfPairs(vector<vector<int>>& points) {
        
        int n = points.size();
        int count = 0;
        sort(points.begin(), points.end());
        // all pairs:
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == j)
                    continue;
                if(chisatoHappy(i, j, points)) {
                    count++;
                }
                else if(chisatoHappy(j, i, points)) {
                    count++;
                }
            }
        }
        return count;
    }
};
