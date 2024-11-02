#include <bits/stdc++.h>
using namespace std;

set<string> ans;
map<char, int> freq;

void backtrack(int i, string& s, string& cur, int n) {
    if (i == n) {
        ans.insert(cur);
        return;
    }

    for(auto &[c, f] : freq) {
        if (f <= 0) continue;

        cur += c;
        f--;
        backtrack(i + 1, s, cur, n);
        f++;
        cur.pop_back();
    }

}

int main() {

    string s;
    cin >> s;

    for(auto &c : s) {
        freq[c]++;
    }
    
    string cur;
    backtrack(0, s, cur, s.size());

    cout << ans.size() << "\n";
    for(auto &str : ans) {
        cout << str << "\n";
    }

    return 0;
}