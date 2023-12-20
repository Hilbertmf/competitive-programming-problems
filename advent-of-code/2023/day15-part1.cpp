#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& s, char separator) {
    vector<string> res;
    string aux;
    stringstream ss(s);
    while (getline(ss, aux, separator)) {
        if(!aux.empty())
            res.push_back(aux);
    }
    return res;
}

int getHash(string& s) {
    int res = 0;

    for(char c : s) {
        res += c;
        res *= 17;
        res %= 256;
    }

    return res;
}

int main() {

    string line;
    cin >> line;
    vector<string> steps = split(line, ',');
    int ans = 0;

    for(auto &s : steps)
        ans += getHash(s);

    cout << ans << "\n";

    return 0;
}