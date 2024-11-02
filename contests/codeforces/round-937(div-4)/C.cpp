#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        string hour_str;
        cin >> hour_str;

        int hour = stoi(hour_str.substr(0, 2));
        int minute = stoi(hour_str.substr(3));
        int minutes = hour * 60 + minute;

        if(minutes < 720) {
            // am
            string str;
            if (hour == 0) {
                str += "12";
                str += hour_str.substr(2);
            }
            else {
                str = hour_str;
            }
            cout << str << " AM" << "\n";
        }
        else {
            // pm
            if (hour > 12)
                hour -= 12;
            string str;
            if (hour < 10)
                str += "0";
            str += to_string(hour);
            str += hour_str.substr(2);
            cout << str << " PM" << "\n";
            
        }


    }
    
    return 0;
}
