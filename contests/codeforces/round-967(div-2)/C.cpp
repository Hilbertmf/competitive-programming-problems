// https://codeforces.com/contest/2001/problem/C
#include <bits/stdc++.h>
using namespace std;

int query(int a, int b, map<pair<int, int>, int>& cache) {
    if (cache.find({a, b}) != cache.end()) {
        return cache[{a, b}];
    }
    cout << "? " << a << " " << b << endl;
    int response;
    cin >> response;
    cache[{a, b}] = response;
    cache[{b, a}] = response; 
    return response;
}

void answer(vector<vector<int>>& tree) {
    cout << "!";
    for (auto &edge : tree) {
        cout << " " << edge[0] + 1 << " " << edge[1] + 1; 
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> tree;
        map<pair<int, int>, int> cache; 

        for (int i = 1; i < n; ++i) {
            int u = 0, v = i;

            while (true) {
                int x = query(u + 1, v + 1, cache) - 1; 
                if (x == -1) {
                    i = n + 1;
                    break;
                }
                if (x == u) {
                    tree.push_back({u, v});
                    break;
                }
                if (x == v) {
                    tree.push_back({v, u});
                    break;
                }
                u = x;
            }
        }
        
        set<pair<int, int>> uniq;
        for (auto& e : tree) {
            if (e.first <= e.second)
                uniq.insert({e.first, e.second});
            else
                uniq.insert({e.second, e.first});
        }

        vector<vector<int>> edges;
        for (auto &e : uniq) {
            edges.push_back({e.first, e.second});
        }
        answer(edges);
    }

    return 0;
}