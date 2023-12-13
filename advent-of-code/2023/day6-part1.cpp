// O(num_races * race_time)
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

vector<int> splitToNums(string& s, char separator = ' ') {
    vector<int> nums;
    stringstream ss(s);
    string curr_str;
    while (getline(ss, curr_str, separator)) {
        bool only_digits = curr_str.find_first_not_of("0123456789", 0) == string::npos;
        if(only_digits && !curr_str.empty())
            nums.push_back(stoi(curr_str));
    }
    
    return nums;
}

int main() {

    string time_line;
    string dist_line;
    getline(cin, time_line);
    getline(cin, dist_line);
    time_line = time_line.substr(time_line.find(':') + 1);
    dist_line = dist_line.substr(dist_line.find(':') + 1);

    vector<int> race_times = splitToNums(time_line);
    vector<int> race_dists = splitToNums(dist_line);

    int num_races = race_times.size();
    int ans = 1;

    for(int r = 0; r < num_races; ++r) {
        int combinations = 0;
        for(int time_hold = 0; time_hold <= race_times[r] / 2; ++time_hold) {
            int remaining_time = race_times[r] - time_hold;
            int v = time_hold;
            int dist = v * remaining_time;
            if(dist > race_dists[r]) {
                combinations++;
                if(time_hold * 2 != race_times[r])
                    combinations++;
            }
        }
        if(combinations > 0)
            ans *= combinations;
    }
    
    cout << ans << "\n";

    return 0;
}