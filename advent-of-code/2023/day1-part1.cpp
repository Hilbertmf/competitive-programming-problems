#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<string> lines;
    string s;

    while (getline(cin, s)) {
        lines.push_back(s);
    }

    int ans = 0;

    for(string& line : lines) {
        int cali = 0;
        
        for(int i = 0; i < line.size(); ++i) {
            if(line[i] >= '0' && line[i] <= '9') {
                cali += (line[i] - '0') * 10;
                break;
            }
        }

        for(int i = line.size() - 1; i >= 0; --i) {
            if(line[i] >= '0' && line[i] <= '9') {
                cali += (line[i] - '0');
                break;
            }
        }
        ans += cali;
    }

    cout << ans << "\n";

    return 0;
}
