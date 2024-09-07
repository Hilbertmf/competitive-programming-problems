#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

bool backtrack(vector<int>& arr, int idx, int sum) {
    if (idx == arr.size())
        return sum == 0;
    sum += arr[idx];
    if (backtrack(arr, idx + 1, sum))
        return true;
    sum -= arr[idx];
    sum -= arr[idx];
    if (backtrack(arr, idx + 1, sum))
        return true;
    return false;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--) {
        int a, b;
        cin >> a >> b;

        vector<int> arr;
        for(int i = 0; i < a; ++i)
            arr.push_back(1);
        for(int i = 0; i < b; ++i)
            arr.push_back(2);

        if (backtrack(arr, 0, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}