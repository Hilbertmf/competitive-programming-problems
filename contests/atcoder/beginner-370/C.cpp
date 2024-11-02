#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;
    string s, t;
    cin >> s >> t;
    vector<string> x;
    vector<int> arr1, arr2;

    for(int i = 0; i < s.size(); ++i) {
        if (s[i] == t[i]) continue;
        if (s[i] > t[i])
            arr1.push_back(i);
        else
            arr2.push_back(i);
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.rbegin(), arr2.rend());
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    for(int i = 0; i < arr1.size(); ++i) {
        s[arr1[i]] = t[arr1[i]];
        x.push_back(s);
    }

    cout << x.size() << "\n";
    for(auto &str : x)
        cout << str << "\n";

    return 0;
}
