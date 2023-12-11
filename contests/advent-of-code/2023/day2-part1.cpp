#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string line;
    map<string, int> max_cubes;
    max_cubes["red"] = 12;
    max_cubes["green"] = 13;
    max_cubes["blue"] = 14;
    int count = 1;
    int ans = 0;

    while (getline(cin, line)) {

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
            if(occ > max_cubes[color]) {
                possible = false;
                break;
            }
        }

        if(possible) {
            ans += count;
        }
        count++;
    }

    cout << ans << "\n";
    return 0;

}