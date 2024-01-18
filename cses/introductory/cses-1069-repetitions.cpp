// https://cses.fi/problemset/task/1069
// time: O(n)
// space: O(1)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;

    string seq;
    cin >> seq;
    int max_length = 1;
    int length = 1;

    for(int i = 1; i < seq.size(); ++i) {
        if(seq[i - 1] == seq[i])
            length++;
        else {
            max_length = max(max_length, length);
            length = 1;
        }
    }
    max_length = max(max_length, length);

    cout << max_length << "\n";

    return 0;
}
