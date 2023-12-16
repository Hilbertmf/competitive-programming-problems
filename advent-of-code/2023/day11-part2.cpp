// time: O(rows * cols)
// space: O(rows * cols)
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int getNumDotsInterval(vector<int>& prefix_sum, int i1, int i2) {
    int sum = 0;
    if(i2 > i1) {
        if(i1 == 0)
            sum += prefix_sum[i2];
        else
            sum += prefix_sum[i2] - prefix_sum[i1 - 1];
    }
    else {
        if(i2 == 0)
            sum += prefix_sum[i1];
        else
            sum += prefix_sum[i1] - prefix_sum[i2 - 1];
    }

    return sum;
}

void initPrefixSum(vector<int>& arr, vector<int>& prefix_sum) {
    prefix_sum[0] = arr[0];
    for(int i = 1; i < arr.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
}

int main() {

    string line;
    vector<string> grid;

    while (getline(cin, line)) {        
        grid.push_back(line);
    }

    vector<int> all_dot_rows(grid.size());
    vector<int> all_dot_cols(grid[0].size());

    for(int i = 0; i < grid.size(); ++i) {
        bool all_dot = grid[i].find_first_not_of('.') == string::npos;
        if(all_dot)  {
            all_dot_rows[i] = 1;
        }
    }

    for(int c = 0; c < grid[0].size(); ++c) {
        bool all_dot = true;
        for(int r = 0; r < grid.size(); ++r) {
            if(grid[r][c] != '.') {
                all_dot = false;
                break;
            }
        }

        if(all_dot) {
            all_dot_cols[c] = 1;
        }
    }

    vector<int> prefix_sum_rows(grid.size());
    vector<int> prefix_sum_cols(grid[0].size());
    initPrefixSum(all_dot_rows, prefix_sum_rows);
    initPrefixSum(all_dot_cols, prefix_sum_cols);

    vector<pair<int, int>> galaxies;
    
    for(int r = 0; r < grid.size(); ++r) {
        for(int c = 0; c < grid[r].size(); ++c) {
            if(grid[r][c] == '#')
                galaxies.push_back({r, c});
        }
    }
    
    long long sum = 0;
    
    for(int i = 0; i < galaxies.size(); ++i) {
        
        int r1 = galaxies[i].first, c1 = galaxies[i].second;

        for(int j = i + 1; j < galaxies.size(); ++j) {
            
            int r2 = galaxies[j].first, c2 = galaxies[j].second;
            sum += abs(r1 - r2) + abs(c1 - c2);
            sum += getNumDotsInterval(prefix_sum_rows, r1, r2) * (1e6 - 1);
            sum += getNumDotsInterval(prefix_sum_cols, c1, c2) * (1e6 - 1);
        }
    }

    cout << sum << "\n";

    return 0;
}