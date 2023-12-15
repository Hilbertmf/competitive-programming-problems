#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {

    string instructions;
    cin >> instructions;
    unordered_map<string, vector<string>> graph;
    string line;
    map<string, int> dists_traveled;
    map<string, int> inst_positions;
    queue<pair<string, string>> qu;

    while (getline(cin, line)) {
        if(line.empty()) continue;

        string node = line.substr(0, 3);
        string left = line.substr(7, 3);
        string right = line.substr(12, 3);
        if(graph[node].empty()) {
            graph[node].push_back(left);
            graph[node].push_back(right);
        }

        if(node.back() == 'A') {
            dists_traveled[node] = -1;
            inst_positions[node] = 0;
            qu.push({node, node});
        }
    }


    while (!qu.empty()) {
        string curr_node = qu.front().first;
        string start_node = qu.front().second;
        qu.pop();
        string next;
        int pos = inst_positions[start_node];

        if(instructions[pos] == 'L') {
            next = graph[curr_node][0];
        }
        else {
            next = graph[curr_node][1];
        }

        dists_traveled[start_node]++;
        inst_positions[start_node]++;
        inst_positions[start_node] %= instructions.size();
        if(curr_node.back() != 'Z') {
            qu.push({next, start_node});
        }
    }

    long long ans = 1;
    
    for(auto &[start, dist] : dists_traveled) {
        ans = lcm(ans, dist);
    }

    cout << ans << "\n";

    return 0;
}