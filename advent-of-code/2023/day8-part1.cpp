#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main() {

    string instructions;
    cin >> instructions;
    unordered_map<string, vector<string>> graph;
    string line;

    while (getline(cin, line)) {
        if(line.empty()) continue;

        string node = line.substr(0, 3);
        string left = line.substr(7, 3);
        string right = line.substr(12, 3);
        if(graph[node].empty()) {
            graph[node].push_back(left);
            graph[node].push_back(right);
        }
    }

    int count = 0;
    string node = "AAA";
    int inst_pos = 0;

    while (node != "ZZZ") {
        count++;

        if(instructions[inst_pos] == 'L') {
            node = graph[node][0];
        }
        else {
            node = graph[node][1];
        }

        inst_pos++;
        inst_pos %= instructions.size();
    }

    cout << count << "\n";

    return 0;
}