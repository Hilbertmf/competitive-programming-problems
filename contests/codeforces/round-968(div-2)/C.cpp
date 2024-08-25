// https://codeforces.com/contest/2003/problem/C
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        string s;
        cin >> n >> s;

        map<char, int> freq;
        for(auto &c : s) freq[c]++;

        vector<pair<int, char>> freq_chars;
        for(auto &[c, f] : freq) {
            freq_chars.push_back({f, c});
        }

        string res;
        priority_queue<pair<int, char>> heap(freq_chars.begin(), freq_chars.end());

        while (heap.size() >= 2) {
            int freq1 = heap.top().first;
            char c1 = heap.top().second;
            heap.pop();
            int freq2 = heap.top().first;
            char c2 = heap.top().second;
            heap.pop();

            res += c1;
            res += c2;
            freq1--; freq2--;
            if (freq1 > 0) {
                heap.push({freq1, c1});
            }
            if (freq2 > 0) {
                heap.push({freq2, c2});
            }
        }

        if (!heap.empty()) {
            int freq1 = heap.top().first;
            char c1 = heap.top().second;
            for(int i = 0; i < freq1; ++i) {
                res += c1;
            }
        }

        cout << res << "\n";
    }
    
    return 0;
}
