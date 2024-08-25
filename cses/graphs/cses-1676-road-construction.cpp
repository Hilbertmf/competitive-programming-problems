#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class UnionFind {
public:

    vector<int> parents;
    vector<int> group_sizes;
    int num_elems;
    int num_groups;
    int largest_group;

    UnionFind(int size) {
        if (size <= 0) return;

        num_elems = size;
        num_groups = size;
        largest_group = 1;
        parents.resize(size);
        group_sizes.resize(size);

        for(int i = 0; i < size; ++i) {
            parents[i] = i;
            group_sizes[i] = 1;
        }
    }

    int find(int node) {

        int root = node;
        while (root != parents[root]) {
            root = parents[root];
        }

        // path compression
        while (node != parents[node]) {
            int next = parents[node];
            parents[node] = root;
            node = next;
        }

        return root;
    }

    int groupSize(int node) {
        return group_sizes[find(node)];
    }

    int size() {
        return num_elems;
    }

    int numComponents() {
        return num_groups;
    }

    int largestComponent() {
        return largest_group;
    }

    void join(int node1, int node2) {

        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 == root2)
            return;

        if (group_sizes[root1] > group_sizes[root2]) {
            group_sizes[root1] += group_sizes[root2];
            parents[root2] = root1;
        }
        else {
            group_sizes[root2] += group_sizes[root1];
            parents[root1] = root2;
        }

        largest_group = max(largest_group, groupSize(root1));
        num_groups--;
    }
};

int main() {
    FASTIO;

    int num_cities, num_roads;
    cin >> num_cities >> num_roads;
    UnionFind cities(num_cities);

    for(int i = 0; i < num_roads; ++i) {
        int a, b;
        cin >> a >> b;
        cities.join(a - 1, b - 1); // index to 0

        cout << cities.numComponents() << " " << cities.largestComponent() << "\n";
    }

    return 0;
}
