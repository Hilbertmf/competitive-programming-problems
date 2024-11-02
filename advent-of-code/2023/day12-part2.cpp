#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define int long long

vector<string> split(string& s, char separator = ' ') {
    stringstream ss(s);
    string tmp;
    vector<string> res;
    while (getline(ss, tmp, separator)) {
        if(!tmp.empty())
            res.push_back(tmp);
    }
    return res;
}

string unfold(string& s, char separator) {
    string res;

    for(int i = 0; i < 5; ++i) {
        res += s;
        res += separator;
    }
    res.erase(res.end() - 1, res.end());

    return res;
}

bool valid(string& symbols, vector<int>& nums, string& possibility, bool thorough) {
        
    for(int i = 0; i < symbols.size(); ++i) {
        if(symbols[i] != '?' && possibility[i] != '?' &&
        symbols[i] != possibility[i])
            return false;
    }

    if(thorough) {

        stringstream ss(possibility);
        string curr_num;
        int nums_idx = 0;
        while (getline(ss, curr_num, '0') && nums_idx < nums.size()) {
            if(curr_num.empty()) continue;
            
            if(curr_num.size() != nums[nums_idx])
                return false;
            nums_idx++;
        }
    }

    return true;
}

int countPossibilities(string& symbols, vector<int>& nums,
vector<vector<string>>& possible_strs) {
    
    int num_unknown = count(symbols.begin(), symbols.end(), '?');
    int nums_sum = accumulate(nums.begin(), nums.end(), 0);
    int sum = 0;
    vector<string> possibilities;
    possibilities.push_back(symbols);
    unordered_set<string> vis;

    while (num_unknown > 0) {

        for(int p = 0; p < possibilities.size(); ++p) {
            
            string possibility = possibilities[p];
            int total_curr_unkown = count(possibility.begin(), possibility.end(), '?');
            if(total_curr_unkown == 0 || vis.find(possibility) != vis.end())
                continue;
            vis.insert(possibility);

            int i = possibility.find_first_of('?');
            int j = possibility.find_first_not_of('?', i);

            int curr_unkown;
            if(j != string::npos) {
                curr_unkown = j - i;
            }
            else {
                curr_unkown = possibility.size() - i;
            }


            string prefix = possibility.substr(0, i);
            string suffix = "";
            if(j < possibility.size())
                suffix = possibility.substr(j);
            
            for(int id = 0; id <= curr_unkown; ++id) {
                for(int k = 0; k < possible_strs[id].size(); ++k) {
                    string s;
                    s += prefix;
                    string tmp(curr_unkown - possible_strs[id][k].size(), '0');
                    tmp += possible_strs[id][k];
                    s += tmp;
                    s += suffix;
                    int num1s = count(s.begin(), s.end(), '1');
                    if(valid(symbols, nums, s, false))
                        possibilities.push_back(s);
                }
            }

        }

        num_unknown = count(possibilities.back().begin(), possibilities.back().end(), '?');
        
        DEBUG(possibilities.back());

        for(auto &p : possibilities) {
            // DEBUG(p);
        }


    }

    for(int i = possibilities.size() - 1; i >= 0; --i) {

        // DEBUG(i);

        int active_bits = count(possibilities[i].begin(), possibilities[i].end(), '1');
        if(active_bits == nums_sum && valid(symbols, nums, possibilities[i], true)) {
            sum++;
        }

        int num_unknown = count(possibilities[i].begin(), possibilities[i].end(), '?');
        if(num_unknown > 0) break;
    }    

    return sum;
}

int32_t main() {

    auto start = std::chrono::high_resolution_clock::now();

    int ans = 0;
    string line;
    vector<string> all_symbols;
    vector<vector<int>> all_nums;

    int largest_unknown_section = 0;
    // set<int> unknown_sections;
    

    while (getline(cin, line)) {
        vector<string> splt = split(line);

        splt[0] = unfold(splt[0], '?');
        splt[1] = unfold(splt[1], ',');

        string symbols = splt[0];
        vector<int> nums;
        stringstream ss(splt[1]);
        string tmp;

        while (getline(ss, tmp, ',')) {
            if(!tmp.empty())
                nums.push_back(stoi(tmp));
        }


        for(int i = 0; i < symbols.size(); ++i) {
            if(symbols[i] == '.') symbols[i] = '0';
            else if(symbols[i] == '#') symbols[i] = '1';
        }

        all_symbols.push_back(symbols);
        all_nums.push_back(nums);

        int i = symbols.find_first_of('?');
        
        for(i; i < symbols.size(); ++i) {
            int j = symbols.find_first_not_of('?', i);
            int sz;
            if(j == string::npos) {
                sz = symbols.size() - i; 
                i = symbols.size();
            }
            else {
                sz = j - i;
            }
            largest_unknown_section = max(largest_unknown_section, sz);
            // if(sz > 0)
                // unknown_sections.insert(sz);
            // DEBUG(sz);
            // DEBUG(symbols);
            // DEBUG(i);
        }


    }

    DEBUG(largest_unknown_section);
    vector<vector<string>> possible_strs(largest_unknown_section + 1);

    int count = 1;
    possible_strs[0].push_back("0");
    for(int i = 1; i <= largest_unknown_section; ++i) {
        // DEBUG(i);

        while (count <= (1 << i) - 1) {
            // DEBUG(count);
            int aux = count;
            string s;

            while (aux > 0) {
                if(aux & 1)
                    s += '1';
                else
                    s += '0';
                aux >>= 1;
            }
            reverse(s.begin(), s.end());
            possible_strs[i].push_back(s);

            count++;

            // DEBUG(s);
        }
    }

    // DEBUG(all_symbols.size());

    for(int l = 0; l < all_symbols.size(); ++l) {
        
        // DEBUG(all_symbols[l]);
        // DEBUG(all_nums[l]);
        
        // brute force it w/ explicit enum.
        // dismember the string into the ? sections
        // and count all possibilities of ? sections
        int curr = countPossibilities(all_symbols[l], all_nums[l], possible_strs);
        // DEBUG(curr);
        ans += curr;

        DEBUG(curr);

        // cout << endl << endl << endl;

    }

    // cout << "\n\n\n";

    // for(auto &vec : possible_strs) {
    //     // DEBUG(key);
    //     for(auto &str : vec) {
    //         DEBUG(str);
    //     }
    // }

    // DEBUG(unknown_sections.size());

    // for(auto &n : unknown_sections) {
    //     DEBUG(n);
    // }

    cout << ans << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " ms" << std::endl;


    return 0;
}