// accepted
// https://neps.academy/br/competition/1356/exercise/1333
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

    vector<long long> players(numPlayers);
    int points = 0;

    int p;
    for(int i = 0, p = 0; i < numPlayers * numRounds; ++i, ++p) {
        p %= numPlayers;
        cin >> points;
        players[p] += points;
    }

    long long maxPoint = *max_element(players.begin(), players.end());

    int player = numPlayers - 1;

    for(int i = numPlayers - 1; i >= 0; --i) {
        if(players[i] == maxPoint) {
            player = i;
            break;
        }
    }

    cout << player + 1;
    
    return 0; 
}
