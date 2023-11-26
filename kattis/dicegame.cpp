// accepted
// https://open.kattis.com/problems/dicegame
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

double median(int low, int high) {
    return (low + high) / 2.0;
}

int32_t main() {
    FASTIO;

    vector<vector<int>> dies(2);
    vector<double> probabilities(2);

    for(int i = 0; i < 2; ++i) {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        probabilities[i] = median(a1, b1) + median(a2, b2);
    }

    if(probabilities[0] > probabilities[1])
        cout << "Gunnar" << "\n";
    else if(probabilities[0] < probabilities[1])
        cout << "Emma" << "\n";
    else
        cout << "Tie" << "\n";


    return 0;
}
