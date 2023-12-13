#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define INF 1e9

vector<string> split(string s, char separator = ' ') {
    vector<string> res;
    stringstream ss(s);
    string curr_str;

    while (getline(ss, curr_str, separator)) {
        bool no_separator = curr_str.find_first_of(separator, 0) == string::npos;
        if(no_separator && !curr_str.empty()) {
            res.push_back(curr_str);
        }
    }

    return res;
}

long long convertToMap(map<long long, long long>& map, long long num) {
    auto it = map.lower_bound(num);
    if(it == map.end()) {
        return num;
    }
    else {
        return num + it->second;
    }
}

int main() {

    string line;
    int count = 1;
    vector<long long> seeds;
    vector<map<long long, long long>> maps;
    
    // add \n to end of input file if there's none
    while (getline(cin, line)) {
        if(count == 1) {
            line = line.substr(line.find(':') + 1);

            vector<string> seeds_str = split(line);
            for(string& seed_str : seeds_str) {
                seeds.push_back(stoll(seed_str));
            }
        }

        else if(line.find("map") != string::npos) {
            string curr_line;
            map<long long, long long> curr_map;
            while (getline(cin, curr_line), !curr_line.empty()) {

                vector<string> data = split(curr_line);
                long long dest = stoll(data[0]);
                long long start = stoll(data[1]);
                long long range = stoll(data[2]);
                
                curr_map[start] = dest - start;
                curr_map[start + range - 1] = dest - start;

            }
            maps.push_back(curr_map);
        }
        count++;
    }


    for(auto &my_map : maps) {
        unordered_map<long long, long long> tmp;
        int count = 0;
        for(auto it = my_map.begin(); it != my_map.end(); ++it, ++count) {
            if(it == my_map.begin())
                tmp[it->first - 1] = 0;
            else if(count & 1) {
                if(next(it) != my_map.end() && next(it)->first - it->first >= 2) {
                    tmp[it->first + 1] = 0;
                    tmp[next(it)->first - 1] = 0;
                }
            }
        }
        
        for(auto &[key, val] : tmp) {
            my_map[key] = val;
        }
        
    }

    long long min_location = INF;
    for(long long seed : seeds) {
        
        for(auto &map : maps) {
            seed = convertToMap(map, seed);
        }
        min_location = min(min_location, seed);
    }

    cout << min_location << "\n";

    return 0;
}