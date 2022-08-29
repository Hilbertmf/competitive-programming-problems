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
    int numPlayers, numRounds;
    cin >> numPlayers >> numRounds;
    vector<int> budgets(numRounds);
    vector<vector<int>> plays(numRounds, vector<int>(numPlayers));
    int extraPoints = 0;
    vector<int> cards{1, 10, 100, 1000, 10000};

    for(int i = 0; i < numRounds; ++i) {
        cin >> budgets[i];
        int sum = 0;
        for(int j = 0; j < numPlayers; ++j) {
            cin >> plays[i][j];
            sum += plays[i][j];
        }

        if(sum > budgets[i] && sum - plays[i][0] < budgets[i]) {
            sum -= plays[i][0];
            extraPoints += *--upper_bound(cards.begin(), cards.end(), budgets[i] - sum);
        }
        else if(budgets[i] - sum + plays[i][0] >= 10000) {
            extraPoints += 10000 - plays[i][0];
        }
        else if(budgets[i] - sum + plays[i][0] >= 1000) {
            extraPoints += 1000 - plays[i][0];
        }
        else if(budgets[i] - sum + plays[i][0] >= 100) {
            extraPoints += 100 - plays[i][0];
        }
        else if(budgets[i] - sum + plays[i][0] >= 10) {
            extraPoints += 10 - plays[i][0];
        }
        else if(budgets[i] - sum + plays[i][0] >= 1) {
            extraPoints += 1 - plays[i][0];
        }
        
    }

    cout << extraPoints << "\n";

    return 0; 
}
