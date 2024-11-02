#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<string> split(string& line) {
    stringstream ss(line);
    string tmp;
    vector<string> words;
    while (getline(ss, tmp, ' ')) {
        if (!tmp.empty())
            words.push_back(tmp);
    }

    return words;
}

int32_t main() {
    FASTIO;

    int n, m, point;
    cin >> n;

    vector<string> lines(n);

    cin.ignore();

    for(int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        lines[i] = line;
    }

    cin >> m;

    map<string, int> points;
    for(int i = 0; i < m; ++i) {
        string s;
        cin >> s >> point;
        points[s] = point;
    }

    int score = 0;
    int best = 0;
    int best_idx = n - 1;
    for(int i = 0; i < n; ++i) {
        vector<string> words = split(lines[i]);
        int curr = 0;

        for(auto &word : words) {
            if (points.find(word) == points.end()) continue;
            
            score += points[word];
            curr += points[word];
        }

        if (curr >= best) {
            best_idx = i;
            best = curr;
        }
    }


    cout << score << " " << best_idx + 1 << "\n";
    
    return 0;
}
