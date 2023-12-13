// O(1)
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

string removeWhitespace(string& s) {
    stringstream ss(s);
    string curr_str;
    string res;
    while (getline(ss, curr_str, ' ')) {
        if(!curr_str.empty())
            res += curr_str;
    }
    
    return res;
}

long long distance(long long time_hold, long long total_time) {
    return time_hold * (total_time - time_hold);
}

int main() {

    string time_line;
    string dist_line;
    getline(cin, time_line);
    getline(cin, dist_line);
    time_line = time_line.substr(time_line.find(':') + 1);
    time_line = removeWhitespace(time_line);
    dist_line = dist_line.substr(dist_line.find(':') + 1);
    dist_line = removeWhitespace(dist_line);

    long long total_time = stoll(time_line);
    long long record_dist = stoll(dist_line);

    // time_hold -> h
    // d(h) = h(T - h) = -h² + Th
    // find h for which d(h) = Record:
    // d(h) = R = -h² + Th => -h² + Th - R = 0
    // delta = T² - 4R
    // hr = (T +- sqrt(delta)) / 2
    // sqrt(delta) < T so both hr are positive, so we want the smaller
    // derivating d(h) = 0, hmax = T/2
    // combinations of answers are all ints in ]hr, hmax] * 2

    long long delta = (total_time * total_time) - 4 * record_dist;
    long long hr = ceil((total_time - sqrt(delta)) / 2.0);
    long long h_max = total_time / 2;
    long long ans = h_max - hr;

    // include hr
    if(distance(hr, total_time) > record_dist)
        ans++;
    
    // get other side of d(h) graph
    ans *= 2;
    
    // if hmax is int then count once
    if(total_time % 2 == 0)
        ans--;

    cout << ans << "\n";

    return 0;
}