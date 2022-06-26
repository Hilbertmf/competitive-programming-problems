// accepted
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
 
int main() { 
    FASTIO;
    string s;
    cin >> s;

    unordered_set<char> st{'a', 'b', 'c'};

    int i = 0;
    int ans = 0;
    int curr = 0;
    while(i < s.size() && s[i] != '&') {
        if(st.find(s[i]) != st.end())
            curr++;
        i++;
    }

    ans = max(curr, ans);

    curr = 0;

    ++i;
    while(i < s.size() && s[i] != '&') {
        if(st.find(s[i]) != st.end())
            curr++;

        i++;
    }
    ++i;

    ans = max(curr, ans);
    curr = 0;
    while(i < s.size()) {
        if(st.find(s[i]) != st.end())
            curr++;

        i++;
    }
    ans = max(curr, ans);
    
    if(ans >= 3) {
        cout << "3-SAT" << "\n";
    }
    else if(ans == 2) {
        cout << "2-SAT" << "\n";
    }
    else {
        cout << "1-SAT" << "\n";

    }
    return 0; 
}
