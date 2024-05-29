#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main() {

    vector<bool> songs(4);

    for(int i = 0; i < 3; ++i) {
        int song;
        cin >> song;
        songs[song] = true;

    }

    for(int i = 1; i <= 3; ++i) {
        if (songs[i] == false)
            cout << i << "\n";
    }

    return 0;
}
