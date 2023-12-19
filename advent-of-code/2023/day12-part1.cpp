#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

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

bool valid(string& symbols, vector<int>& nums, int bit) {
    int curr_bit = bit;
    int count = 0;
    int n = symbols.size();
    bitset<29> bit_set(bit);
    string bit_str = bit_set.to_string();
    
    reverse(bit_str.begin(), bit_str.end());
    if(bit_str.size() > symbols.size()) {
        bit_str.resize(symbols.size());
    }
    
    for(int i = 0; i < symbols.size(); ++i) {
        if(symbols[i] != '?' && symbols[i] != bit_str[i])
            return false;
    }

    stringstream ss(bit_str);
    string curr_num;
    int nums_idx = 0;
    while (getline(ss, curr_num, '0') && nums_idx < nums.size()) {
        if(curr_num.empty()) continue;
        
        if(curr_num.size() != nums[nums_idx])
            return false;
        nums_idx++;
    }

    return true;
}

int countPossibilities(string& symbols, vector<int>& nums) {
    int sz = symbols.size();
    int bit = (1 << sz) - 1;
    int nums_sum = accumulate(nums.begin(), nums.end(), 0);
    int sum = 0;

    while (bit > 0) {

        int active_bits = __builtin_popcount(bit);
        if(active_bits == nums_sum && valid(symbols, nums, bit)) {
            sum++;
        }

        bit--;
    }

    return sum;
}

int main() {


    auto start = std::chrono::high_resolution_clock::now();

    int ans = 0;
    string line;
    while (getline(cin, line)) {
        vector<string> splt = split(line);
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

        // brute force it w/ explicit enum.
        ans += countPossibilities(symbols, nums);
    }

    cout << ans << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " ms" << std::endl;

    return 0;
}