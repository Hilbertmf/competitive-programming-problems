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

    int n, ans = 0;
    cin >> n;
    vector<int> sequence(n);
    for(auto &num : sequence) {
        cin >> num;
    }
    sort(sequence.begin(), sequence.end());

    map<int, int> occurrences;
    for(auto num : sequence) {
        occurrences[num]++;
    }

    // remove duplicates
    auto it = unique(sequence.begin(), sequence.end());
    sequence.erase(it, sequence.end());
    
    // remove the isolated nums
    set<int> isolated;

    if (sequence.size() > 1 && sequence[0] + 1 != sequence[1]) {
        isolated.insert(sequence[0]);
    }
    if (sequence.size() > 1 && sequence.back() - 1 != sequence[sequence.size() - 2]) {
        isolated.insert(sequence.back());
    }
    for(int i = 1; i < sequence.size() - 1; ++i) {
        if (sequence[i] - 1 != sequence[i - 1] && sequence[i] + 1 != sequence[i + 1])
            isolated.insert(sequence[i]);
    }

    for(auto num : isolated) {
        ans += occurrences[num] * num;
    }

    vector<int> ordered_seq(1);
    for(auto num : sequence) {
        if (isolated.find(num) == isolated.end()) // does not contain
            ordered_seq.push_back(num);
    }

    // dp-like solution (climbing stairs)
    int best = 0, prev = 0, prev_prev = 0;
    for(int i = 1; i < ordered_seq.size(); ++i) {
        // new ordered sequence
        if (i > 1 && ordered_seq[i] - 1 != ordered_seq[i - 1]) {
            // ended dp, new dp
            ans += max(best, prev);
            prev = 0;
            prev_prev = 0;
        }
        
        int include, exclude, cur = ordered_seq[i];
        if (i - 2 < 0)
            include = occurrences[cur] * cur;
        else
            include = occurrences[cur] * cur + prev_prev;
        exclude = prev;
        best = max(include, exclude);
        prev_prev = prev;
        prev = best;
    }

    best = max(best, prev);
    ans += best;
    cout << ans << "\n";
    return 0;
}
