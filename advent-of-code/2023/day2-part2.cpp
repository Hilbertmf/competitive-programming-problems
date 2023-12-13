#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string line;
    int ans = 0;

    while (getline(cin, line)) {

        map<string, int> max_cubes;
        line = line.substr(line.find(':') + 2);

        // remove moves all 'removed' chars to the end of the str
        // then returns a ptr to the first of those chars
        // erase removes all elems in range
        line.erase(
            remove(line.begin(), line.end(), ';'), line.end());
        line.erase(
            remove(line.begin(), line.end(), ','), line.end());

        stringstream ss(line);
        bool possible = true;

        while (!ss.eof()) {
            int occ;
            string color;
            ss >> occ >> color;
            max_cubes[color] = max(max_cubes[color], occ);
        }

        ans += max_cubes["red"] * max_cubes["green"] * max_cubes["blue"];

    }

    cout << ans << "\n";
    return 0;

}