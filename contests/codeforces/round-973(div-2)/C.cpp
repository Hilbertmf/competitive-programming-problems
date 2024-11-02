#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int query(string& t) {
    cout << "? " << t << endl;
    int response;
    cin >> response;
    return response;
}

void answer(string& s) {
    cout << "! " << s << endl;
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string x = "0";
        if (!query(x))
            x = "1";

        while (x.size() < n) {
            string test = "0" + x;
            if (query(test)) {
                x = test;
                continue;
            }
            test = "1" + x;
            if (query(test)) {
                x = test;
                continue;
            }
            break;
        }

        while (x.size() < n) {
            string test = x + "0";
            if (query(test)) {
                x = test;
                continue;
            }
            x = x + "1";
        }
                
        answer(x);
    }

    return 0;
}
