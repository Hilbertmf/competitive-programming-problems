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

    int num_foods, num_nutrients;
    cin >> num_foods >> num_nutrients;

    vector<int> goals(num_nutrients);
    for(int i = 0; i < num_nutrients; ++i) {
        cin >> goals[i];
    }

    vector<vector<int>> intake_matrix(num_foods, vector<int>(num_nutrients));

    vector<int> intake(num_nutrients);
    
    for(int i = 0; i < num_foods; ++i) {
        for(int j = 0; j < num_nutrients; ++j) {
            cin >> intake_matrix[i][j];
            intake[j] += intake_matrix[i][j];
        }
    }

    bool met_goal = true;

    for(int i = 0; i < num_nutrients && met_goal; ++i) {
        if (intake[i] < goals[i])
            met_goal = false;
    }

    if(met_goal) {
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }

    return 0;
}
