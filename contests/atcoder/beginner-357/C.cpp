#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
// #define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<vector<char>> generate(int k) {
    vector<vector<char>> grid;
    if (k == 0) {
        grid = vector<vector<char>> (1);
        grid[0].push_back('#');
        return grid;
    }

    int rows = pow(3, k);
    int cols = rows;
    int prev = rows / 3;
    
    grid = vector<vector<char>> (rows, vector<char>(cols));

    // mid:
    for(int r = prev; r < prev * 2; ++r) {
        for(int c = prev; c < prev * 2; ++c) {
            grid[r][c] = '.';
        }
    }

    vector<int> dr {0, prev, prev * 2, 0, prev * 2, 0, prev, prev * 2};
    vector<int> dc {0, 0, 0, prev, prev, prev * 2, prev * 2, prev * 2};
    
    
    vector<vector<char>> prev_grid = generate(k - 1);
    
    for(int i = 0; i < 8; ++i) {
        for(int r = 0; r < prev; ++r) {
            for(int c = 0; c < prev; ++c) {
                int curr_row = r + dr[i];
                int curr_col = c + dc[i];
                grid[curr_row][curr_col] = prev_grid[r][c];
            }
        }
    }

    return grid;
}

int32_t main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<char>> grid = generate(n);

    for(int r = 0; r < grid.size(); ++r) {
        for(int c = 0; c < grid[0].size(); ++c) {
            cout << grid[r][c];
        }
        cout << "\n";
    }

    return 0;
}



/*
[4,5,0,-2,-3,1]

[1,2,3,4,5,6] 6 + 5 + 4 + 3 + 2 + 1 = 21
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int subarrs = 0;
        unordered_map<int, int> count;
        count.reserve(nums.size());
        count[0] = 1;
        int sum = 0;

        for(int num : nums) {
            sum += num;
            sum %= k;
            if (sum < 0)
                sum += k;
            count[sum]++;
            if (count[sum] > 1)
                subarrs += count[sum] - 1;
        }

        return subarrs;
    }
};

/*
   v
[1,2,3,4,5,1]

ex = 1
in = 
count: 0
*/

class Solution {
public:
    vector<int> order;

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int MAX = *max_element(arr1.begin(), arr1.end());
        order = vector<int>(MAX + 1, -1);
        for(int i = 0; i < arr2.size(); ++i) {
            order[arr2[i]] = i;
        }

        auto cmp = [this](int lhs, int rhs) {
            if (order[lhs] != -1 && order[rhs] != -1) {
                return order[lhs] < order[rhs];
            }
            else if (order[lhs] != -1)
                return true;
            else if (order[rhs] != -1)
                return false;
            return lhs < rhs;
        };

        sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }
};