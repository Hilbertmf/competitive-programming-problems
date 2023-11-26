#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

struct point {
    int x;
    int y;
};

set<vector<int>> getPythagoreanTriples(int hypotenuse) {
    set<vector<int>> tuples;
    for(int i = 1; i < hypotenuse; ++i) {
        int cathetus_sqr = (hypotenuse * hypotenuse) - (i*i);

        if(sqrt(cathetus_sqr) == floor(sqrt(cathetus_sqr))) { // perfect square
            int cat = sqrt(cathetus_sqr);
            vector<int> tmp{i, cat};
            sort(tmp.begin(), tmp.end());
            tuples.insert(tmp);
        }
    }

    return tuples;
}

bool finds(int dx, int dy, map<int, set<int>>& map) {
    return map.find(dx) != map.end() &&
    map[dx].find(dy) != map[dx].end();
}

void insertInSolution(set<vector<vector<int>>>& solutions,
point& p1, point& p2) {
    vector<vector<int>> tmp {{p1.x, p1.y}, {p2.x, p2.y}};
    sort(tmp.begin(), tmp.end());
    solutions.insert({tmp});
}

int32_t main() {
    FASTIO;

    int num_points;
    cin >> num_points;

    vector<point> points(num_points);
    map<int, set<int>> points_mapped_by_x;
    for(auto &point : points) {
        cin >> point.x >> point.y;
        points_mapped_by_x[point.x].insert(point.y);
    }

    set<vector<int>> pythagorean_tuples = getPythagoreanTriples(2018);
    pythagorean_tuples.insert({0, 2018});
    set<vector<vector<int>>> solutions;

    for(auto &p : points) {
        for(auto &tuple : pythagorean_tuples) {
            // x coordinate possibilities: p.x +- tuple[0]/tuple[1]

            for(int t = 0; t <= 1; ++t) {
                int x = tuple[t], y = tuple[t^1];
                int dx = p.x + x;
                int dy = p.y + y;
                point p1 {dx, dy};
                if(finds(dx, dy, points_mapped_by_x))
                    insertInSolution(solutions, p, p1);

                dy = p.y - y;
                p1.y = dy;
                if(finds(dx, dy, points_mapped_by_x))
                    insertInSolution(solutions, p, p1);

                dx = p.x - x;
                p1.x = dx;
                if(finds(dx, dy, points_mapped_by_x))
                    insertInSolution(solutions, p, p1);

                dy = p.y + y;
                p1.y = dy;
                if(finds(dx, dy, points_mapped_by_x))
                    insertInSolution(solutions, p, p1);

            }
        }
    }

    cout << solutions.size() << "\n";

    return 0;
}
