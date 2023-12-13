#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

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

int main() {

    string line;
    int count = 1;
    map<int, int> cards;

    while (getline(cin, line)) {
        cards[count]++;
        line = line.substr(line.find(':') + 1);
        vector<string> scratchcard_nums = split(line, '|');
        vector<string> winning_cards;
        winning_cards = split(scratchcard_nums[0]);
        vector<string> my_nums;
        my_nums = split(scratchcard_nums[1]);
        unordered_set<string> winning_cards_set(winning_cards.begin(), winning_cards.end());

        int matches = 0;
        for(string& num : my_nums) {
            if(winning_cards_set.find(num) != winning_cards_set.end()) {
                matches++;
            }
        }

        for(int i = count + 1; i <= count + matches; ++i) {
            cards[i] += cards[count];
        }

        count++;
    }

    int num_cards = 0;
    for(auto &[card, num] : cards) {
        num_cards += num;
    }
    
    cout << num_cards << "\n";

    return 0;
}