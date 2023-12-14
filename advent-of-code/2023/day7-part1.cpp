#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

map<char, int> order = {
    {'A', 13},
    {'K', 12},
    {'Q', 11},
    {'J', 10},
    {'T', 9},
};
map<string, int> type;

vector<string> split(string& s, char separator = ' ') {
    vector<string> strs;
    stringstream ss(s);
    string curr_str;
    while (getline(ss, curr_str, separator)) {
        strs.push_back(curr_str);
    }
    
    return strs;
}

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

int getType(string& s) {
    map<char, int> count;
    int more_common_char = 0;
    vector<int> num_occurences;
    for(char c : s) count[c]++;
    for(auto &[key, val] : count) {
        num_occurences.push_back(val);
    }
    sort(num_occurences.rbegin(), num_occurences.rend());
    
    // 5/4 of a kind
    if(num_occurences[0] == 5 || num_occurences[0] == 4) {
        return num_occurences[0];
    }
    // full house
    else if(num_occurences[0] == 3 && num_occurences[1] == 2) {
        return 3;
    }
    // 3 of a kind
    else if(num_occurences[0] == 3) {
        return 2;
    }
    // 2 pairs
    else if(num_occurences[0] == 2 && num_occurences[1] == 2) {
        return 1;
    }
    // 1 pair
    else if(num_occurences[0] == 2) {
        return 0;
    }
    else {
        return -1;
    }
    
}

bool cmp(string& lhs, string& rhs) {
    if(type[lhs] == type[rhs]) {
        for(int i = 0; i < lhs.size(); ++i) {
            if(order[lhs[i]] != order[rhs[i]])
                return order[lhs[i]] < order[rhs[i]];
        }
        return order[lhs[0]] < order[rhs[0]];
    }
    else {
        return type[lhs] < type[rhs];
    }
}

int main() {

    string line;
    vector<string> hands;
    map<string, int> bid_map;

    for(int i = 9; i >= 2; --i) {
        order['0' + i] = i - 1;
    }
    
    while (getline(cin, line)) {
        vector<string> input = split(line, ' ');
        string hand = input[0];
        string bid_str = input[1];
        bid_str = removeWhitespace(bid_str);
        int bid = stoi(bid_str);
        bid_map[hand] = bid;
        hands.push_back(hand);
        type[hand] = getType(hand);
    }

    sort(hands.begin(), hands.end(), cmp);
    int res = 0;

    for(int i = 0; i < hands.size(); ++i) {
        res += (i + 1) * bid_map[hands[i]];
    }

    cout << res << "\n";

    return 0;
}