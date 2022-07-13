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
 
void move(int pos, vector<int>& digits, vector<vector<char>>& moves) {
    for(int i = 0; i < moves[pos].size(); ++i) {
        if(moves[pos][i] == 'U') {
            digits[pos] += 1;
            digits[pos] %= 10;
        }
        if(moves[pos][i] == 'D') {
            digits[pos] -= 1;
            if(digits[pos] < 0) digits[pos] = 9;
        }
    }
}

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int numWheels;
        cin >> numWheels;
        vector<int> digits(numWheels);
        for(int i = 0; i < numWheels; ++i) cin >> digits[i];
        
        vector<vector<char>> moves(numWheels, vector<char>());

        for(int i = 0; i < numWheels; ++i) {
            int numMoves;
            cin >> numMoves;
            moves[i] = vector<char>(numMoves);
            for(int j = 0; j < numMoves; ++j) {
                cin >> moves[i][j];
                if(moves[i][j] == 'U') moves[i][j] = 'D';
                else if(moves[i][j] == 'D') moves[i][j] = 'U';
            }
        }

        for(int i = 0; i < numWheels; ++i) {
            move(i, digits, moves);
        }

        for(int i = 0; i < numWheels; ++i) {
            cout << digits[i];
            if(i != numWheels - 1)
                cout << " ";
        }
        cout << "\n";
    }	
    
    return 0; 
}
