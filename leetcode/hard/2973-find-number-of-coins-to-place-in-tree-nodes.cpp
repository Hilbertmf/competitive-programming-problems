// Solution article: https://leetcode.com/problems/find-number-of-coins-to-place-in-tree-nodes/solutions/4454491/c-solution-using-dfs-and-multiset/
// Time: O(10V)
// Space: O(V)
class Solution {
public:
    const long long INF = 1e18;
    const int SHORT_INF = 1e9;

    void insertInNums(multiset<int>& nums, vector<int>& v1, vector<int>& v2) {
        for(int num : v1)
            if(num != SHORT_INF) nums.insert(num);
        for(int num : v2)
            if(num != SHORT_INF) nums.insert(num);
    }

    void insertNumsToMaxMin(multiset<int>& nums, vector<int>& max_nums,
    vector<int>& min_nums) {
        vector<int> removed_items;
        int count = 0;
        for(auto it = nums.rbegin(); it != nums.rend() && count < 3; ++it, ++count) {
            max_nums.push_back(*it);
            removed_items.push_back(*it);
        }
        for(int n : removed_items)
            nums.erase(nums.find(n));
        count = 0;
        for(auto it = nums.begin(); it != nums.end() && count < 2; ++it, ++count)
            min_nums.push_back(*it);
    }

    pair<vector<int>, vector<int>> dfs(int vertex, vector<vector<int>>& tree, vector<int>& cost,
    vector<pair<vector<int>, vector<int>>>& nums_to_mul, vector<bool>& vis) {

        // if leaf
        if(tree[vertex].size() == 0) {
            nums_to_mul[vertex] = {{cost[vertex]}, {SHORT_INF}};
            return {{cost[vertex]}, {SHORT_INF}};
        }

        vector<int> min_nums;
        vector<int> max_nums;

        for(int adj : tree[vertex]) {
            if(vis[adj]) continue;
            
            vis[adj] = true;

            auto adj_vec_pair = dfs(adj, tree, cost, nums_to_mul, vis);

            multiset<int> nums;
            insertInNums(nums, adj_vec_pair.first, adj_vec_pair.second);
            insertNumsToMaxMin(nums, max_nums, min_nums);
        }
        

        multiset<int> nums;
        insertInNums(nums, max_nums, min_nums);
        nums.insert(cost[vertex]);
        max_nums.clear();
        min_nums.clear();       
        insertNumsToMaxMin(nums, max_nums, min_nums);

        nums_to_mul[vertex] = {max_nums, min_nums};

        return nums_to_mul[vertex];
    }
    
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {

        vector<vector<int>> tree(edges.size() + 1);
        vector<long long> coins(tree.size());
        
        for(auto &edge : edges) {
            int v = edge[0], u = edge[1];
            tree[v].push_back(u);
            tree[u].push_back(v);
        }

        // for every node get 3 largest and 2 smallest
        // in their subtree
        vector<pair<vector<int>, vector<int>>> nums_to_mul(edges.size() + 1);

        vector<bool> vis(tree.size());
        vis[0] = true;
        dfs(0, tree, cost, nums_to_mul, vis);
        
        for(int i = 0; i < nums_to_mul.size(); ++i) {
            
            vector<long long> nums;
            for(int j = 0; j < nums_to_mul[i].first.size(); ++j) {
                if(nums_to_mul[i].first[j] != SHORT_INF)
                    nums.push_back(nums_to_mul[i].first[j]);
            }
            for(int j = 0; j < nums_to_mul[i].second.size(); ++j) {
                if(nums_to_mul[i].second[j] != SHORT_INF)
                    nums.push_back(nums_to_mul[i].second[j]);
            }

            if(nums.size() < 3) {
                coins[i] = 1;
                continue;
            }
            
            long long prod = -INF;            
            int count = 0;
            for(int j = 0; j < nums.size() - 2; ++j) {
                for(int k = j + 1; k < nums.size() - 1; ++k) {
                    for(int l = k + 1; l < nums.size(); ++l) {
                        prod = max(prod, nums[j] * nums[k] * nums[l]);
                        count++;
                    }
                }
            }

            if(prod < 0) {
                coins[i] = 0;
            }
            else {
                coins[i] = prod;
            }
        }

        return coins;
    }
};