#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
// #define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<int> dr {1, -1, 0, 0};
vector<int> dc {0, 0, 1, -1};

bool valid(int row, int col, vector<vector<char>>& grid) {
    return row >= 0 && row < grid.size() &&
           col >= 0 && col < grid[0].size();
}

bool isCoast(int row, int col, vector<vector<char>>& grid) {
    if (row == 0 || row == grid.size() - 1 ||
        col == 0 || col == grid[0].size() - 1)
        return true;
    
    for(int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (!valid(nr, nc, grid)) continue;
        if (grid[nr][nc] == '.') return true;
    }
    return false;
}

int32_t main() {
    FASTIO;
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if (grid[i][j] == '#' && isCoast(i, j, grid))
                ans++;
        }
    }

    cout << ans << "\n";



    return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// time: O(nlogn)
// space: O(1)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());

        for(int i = 0; i < k; ++i) {
            happiness[i] -= i;
            if (happiness[i] > 0)
                sum += happiness[i];
        }

        return sum;
    }
};
/*

      v
v
1 2 3 5

1/5, min(2/5, 1/3) = 1/3, min(2/5, 1/2) = 2/5, min(3/5)  min(1/3, 2/5) = 1/3, min(2/3, 2/5) = 2/5, min()


*/

class Solution {
public:
    struct state {
        double val;
        int id1;
        int id2;

        state(double v, int p1, int p2) : val(v), id1(p1), id2(p2) {}

        bool operator<(const state& other) const {
            return val > other.val;
        }
    };    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        int n = arr.size();
        vector<state> tmp;
        tmp.reserve(n - 1);
        for(int i = 1; i < n; ++i) {
            tmp.push_back((state){1.0 / arr[i], 0, i});
        }
        priority_queue<state> heap(tmp.begin(), tmp.end());


        for(int i = 0; i < k - 1; ++i) {
            int idx1 = heap.top().id1;
            int idx2 = heap.top().id2;
            heap.pop();

            idx1++;
            if (idx1 >= n) continue;
            int denominator = arr[idx1];
            int numerator = arr[idx2];
            heap.push((state){(double)denominator / numerator, idx1, idx2});
        }

        vector<int> ans = {(int)heap.top().id1,
                           (int)heap.top().id2};
        return ans;
    }
};




class Solution {
public:
    const double INF = numeric_limits<double>::max();
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans = INF;
        int n = quality.size();
        
        // for every i, other elements:
        // e = w[i] * q[j] / q[i] if e >= w[j]
        // e = (w[i] / q[i]) * q[j] >= w[j]
        // w[i] / q[i] is constant 
        // e = k * q[j]
        // thus we wan to minimize q[j] for elements that satisfy:
        // w[i] / q[i] >= w[j] / q[j]

        vector<pair<double, int>> proportions(n);

        for(int i = 0; i < n; ++i) {
            proportions[i] = {(double)wage[i] / quality[i], i};
        }

        sort(proportions.begin(), proportions.end());
        vector<int> prefix_quality(n + 1);
        prefix_quality[0] = 0;
        priority_queue<int> heap;

        for(int i = 1; i <= k; ++i) {
            int curr = quality[proportions[i - 1].second];
            prefix_quality[i] = prefix_quality[i - 1] +
                                curr;
            heap.push(curr);
        }

        for(int i = k + 1; i <= n; ++i) {
            int curr = quality[proportions[i - 1].second];
            prefix_quality[i] = prefix_quality[i - 1];
            if (curr < heap.top()) {
                prefix_quality[i] -= heap.top();
                prefix_quality[i] += curr;
                heap.pop();
                heap.push(curr);
            }
        }

        for(int i = 0; i < n; ++i) {

            double proportion = (double)wage[i] / quality[i];
            auto comp = [](const pair<double,int> &p1, const pair<double,int> &p2) {
                return p1.first < p2.first;
            };

            pair<double, int> p = {proportion, 0};
            auto it = upper_bound(
                      proportions.begin(), proportions.end(), p, comp);
            
            if (it == proportions.begin()) continue;

            int idx = distance(proportions.begin(), prev(it));
            if (idx + 1 < k) continue;

            double curr_ans = prefix_quality[idx + 1] * proportion;

            ans = min(ans, curr_ans);
        }

        return ans;
    }
};


// time: O(n² + n²logn)
// space: O(n²)
class Solution {
public:
    vector<int> dr {1, -1, 0, 0};
    vector<int> dc {0, 0, 1, -1};

    bool valid(int r, int c, vector<vector<int>>& safeness) {
        return r >= 0 && r < safeness.size() &&
               c >= 0 && c < safeness[0].size();
    }
    
    // multisource bfs
    void getSafeness(vector<pair<int, int>>& thieves,
    vector<vector<int>>& safeness) {
        queue<vector<int>> qu;
        for(auto &[r, c] : thieves) {
            safeness[r][c] = 0;
            qu.push({0, r, c});
        }

        while (!qu.empty()) {
            int dist = qu.front()[0];
            int r = qu.front()[1];
            int c = qu.front()[2];
            qu.pop();

            for(int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (!valid(nr, nc, safeness) || safeness[nr][nc] != -1)
                    continue;

                safeness[nr][nc] = dist + 1;
                qu.push({dist + 1, nr, nc});
            }
        }
    }

    int minPath(vector<vector<int>>& safeness) {
        int n = safeness.size();
        vector<vector<char>> vis(n, vector<char>(n, 0));
        priority_queue<vector<int>> qu;
        qu.push({safeness[0][0], 0, 0});
        vis[0][0] = 1;
        
        while (!qu.empty()) {
            int safety = qu.top()[0];
            int r = qu.top()[1];
            int c = qu.top()[2];

            if (r == n - 1 && c == n - 1)
                return safety;

            qu.pop();

            for(int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (!valid(nr, nc, safeness) || vis[nr][nc] == 1)
                    continue;
                vis[nr][nc] = 1;
                qu.push({min(safety, safeness[nr][nc]), nr, nc});

            }
        }

        return -1;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        vector<pair<int, int>> thieves;
        thieves.reserve(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    thieves.push_back({i, j});
            }
        }
        
        getSafeness(thieves, safeness);
        
        return minPath(safeness);
    }
};




/*

para cada nó, faça bfs
vc terá a distancia dele para tds os outros zero
entao guarde num map<int, list<nó>> tds os nós e as 
distancias

após isso ordene esses mapas e se houver empate, desempate pelo
size de cada lista, assim começaremos pelos nós q tem o minimo nº
de candidatos p/ distancia minima (de preferencia 1, unicos)

após ordenar 

*/

class Solution {
public:
    int xorWithElems(int bit, vector<int>& nums) {
        int res = 0, i = 0;
        while (bit) {
            if (bit & 1)
                res ^= nums[i];
            bit >>= 1;
            i++;
        }
        return res;
    }
    
    int subsetXORSum(vector<int>& nums) {

        int n = nums.size();
        int bit = (1 << n) - 1;
        int sum = 0;
        while (bit) {
            int curr_bit = bit;
            sum += xorWithElems(curr_bit, nums);
            bit--;
        }

        return sum;
    }
};


class Solution {
public:
void addSubset(vector<vector<int>>& sets,
vector<int>& nums, int bit) {
        vector<int> tmp;
        for(int i = 0; bit; ++i, bit >>= 1) {
            if (bit & 1) {
                tmp.push_back(nums[i]);
            }
        }
        sets.push_back(tmp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int bit = (1 << n) - 1;
        vector<vector<int>> sets;
        sets.push_back({});

        while (bit) {
            addSubset(sets, nums, bit);
            bit--;
        }

        return sets;
    }
};


/*

a
,
b
c
,
b
,
a

00000
abcba

1 0100
a,bc,ba

11 110
a,b,c,b,a


abab

b = 1110

*/

class Solution {
public:
    bool isPalindrome(string& s) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        return tmp == s;
    }

    void checkPalindrome(vector<string>& curr_partition,
    string& curr, bool& all_palindrome) {
        if (isPalindrome(curr)) {
            curr_partition.push_back(curr);
            curr.clear();
        }
        else {
            all_palindrome = false;
        }
    }

    vector<string> partitionString(string& s, int bit, bool& all_palindrome) {
        vector<string> curr_partition;
        string curr;
        int i;
        for(i = 0; bit && all_palindrome; ++i, bit >>= 1) {
            curr += s[i];
            if (bit & 1) {
                checkPalindrome(curr_partition, curr, all_palindrome);
            }
        }

        if (!all_palindrome) return curr_partition;
        
        for(; i < s.size(); ++i) {
            curr += s[i];
        }
        checkPalindrome(curr_partition, curr, all_palindrome);
        return curr_partition;        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> strs;
        int sz = 1;
    
        int n = s.size();
        int bit = (1 << (n - 1)) - 1;

        while (bit) {
            bool sucessful = true;
            vector<string> tmp = partitionString(s, bit, sucessful);
            if (sucessful)
                strs.push_back(tmp);
            bit--;
        }

        if (isPalindrome(s))
            strs.push_back({s});

        return strs;
    }
};


// everything in the same function
// to run faster
class Solution {
public:

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0;
        int bit = (1 << n) - 1;

        while (bit) {
            
            int curr_bit = bit;
            const int sz = __popcount(curr_bit);
            int set_nums[sz];
            bool is_beautiful = true;

            for(int i = 0, j = 0; curr_bit; ++i, curr_bit >>= 1) {
                if (curr_bit & 1) {
                    set_nums[j] = nums[i];
                    ++j;
                }
            }
            
            for(int i = 0; i < sz - 1 && is_beautiful; ++i) {
                for(int j = i + 1; j < sz && is_beautiful; ++j) {
                    if (set_nums[j] - set_nums[i] == k)
                        is_beautiful = false;
                }
            }
            
            if (is_beautiful)
                ++count;
            --bit;
        }
        return count;
    }
};

// abcdazzaz
// a: 1 2 3

class Solution {
public:
    string getSentence(int bit, string& s, unordered_set<string>& words) {
        string ret, curr;
        int i;

        for(i = 0; bit; ++i, bit >>= 1) {
            curr += s[i];
            if (bit & 1) {
                if (words.find(curr) == words.end())
                    return "";
                ret += curr;
                ret += " ";
                curr.clear();
            }
        }

        for(; i < s.size(); ++i) {
            curr += s[i];
        }

        if (words.find(curr) == words.end())
            return "";

        ret += curr;

        return ret;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int bit = (1 << n - 1) - 1;
        vector<string> ans;

        unordered_set<string> words(wordDict.begin(), wordDict.end());

        if (words.find(s) != words.end())
            ans.push_back(s);

        while (bit) {
            string sentence = getSentence(bit, s, words);
            if (!sentence.empty())
                ans.push_back(sentence);
            bit--;
        }

        return ans;
    }
};