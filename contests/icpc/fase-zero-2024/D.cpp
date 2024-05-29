#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

signed main() {
    FASTIO;

    int dist, speed;
    cin >> dist >> speed;

    int time_min = (dist * 60 / (double)speed);
    int curr_time = 19 * 60;
    curr_time += time_min;
    if (curr_time >= 24 * 60)
        curr_time %= 24 * 60;

    int hours = curr_time / 60;
    int min = curr_time % 60;

    if (hours < 10)
        cout << "0";
    cout << hours << ":";
    if (min < 10)
        cout << "0";
    cout << min << "\n";

    return 0;
}
