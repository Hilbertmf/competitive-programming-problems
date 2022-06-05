// memory exceeded (but i think it gets the right answer)
// https://codeforces.com/contest/1688/problem/C
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

struct state {
    string s;
    unordered_multiset<string> availableStrings;
};

class Comparator {
    public:
    bool operator() (const state& lhs, const state& rhs) {
        return lhs.s.size() > rhs.s.size();
    }
};

string optimizedBfs(string start, unordered_set<string>& visited, unordered_multiset<string>& possibleSubstr) {
    priority_queue<state, vector<state>, Comparator> pq;
    pq.push((state){start, possibleSubstr});

    int count = 0;
    while (!pq.empty()) {
        ++count;
        
        struct state currState = pq.top();
        pq.pop();

        if(currState.s.size() == 1 && currState.availableStrings.size() == 0) {
            cout << "found! It took " << count << " operations" << "\n";
            return currState.s;
        }
        
        if(visited.find(currState.s) != visited.end()) continue;
        visited.insert(currState.s);
        if(currState.availableStrings.size() <= 1) continue;
        
        // traverse neighbors
        for(auto it1 = currState.availableStrings.begin();
         it1 != currState.availableStrings.end(); ++it1) {
            auto idx = currState.s.find(*it1);
            while(idx != string::npos) {

                 
                for(auto it2 = currState.availableStrings.begin();
                it2 != currState.availableStrings.end(); ++it2) {
                    if(it1 == it2) continue;

                    unordered_multiset<string> tmpSet = currState.availableStrings;
                    tmpSet.erase(tmpSet.find(*it1));
                    tmpSet.erase(tmpSet.find(*it2));
                    string newStr = currState.s.substr(0, idx) + *it2 + currState.s.substr(idx + (*it1).size());

                    pq.push((state){newStr,tmpSet});
                }

                idx += (*it1).size();
                idx = currState.s.find(*it1, idx);
            }

        }
    }
    return "could not find";
}

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int numOperations;
        cin >> numOperations;
        vector<string> sequence(numOperations * 2);
        for(int i = 0; i < sequence.size(); ++i) cin >> sequence[i];
        string finalStr;
        cin >> finalStr;

        unordered_multiset<string> possibleSubstr(sequence.begin(), sequence.end());
        unordered_set<string> visited;		

        cout << optimizedBfs(finalStr, visited, possibleSubstr) << "\n";
    }	
    
    return 0; 
}
