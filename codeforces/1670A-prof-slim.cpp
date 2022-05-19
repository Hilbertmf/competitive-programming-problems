// https://codeforces.com/contest/1670/problem/A
// time: O(n)
// space: O(1)
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
	int t;
	cin >> t;
	while (t--) {
        int length;
        cin >> length;
        vector<int> seq(length);
        int positives = 0, numNegatives = 0;
        bool possible = true;

        for(auto &num : seq) {
            cin >> num;
            
            if(num > 0) positives++;
            else numNegatives++;
        }

        for(int i = 0; possible && i < numNegatives - 1; ++i) {
            if(abs(seq[i]) < abs(seq[i+1]))
                possible = false;
        }

        for(int i = numNegatives; i < length - 1; ++i) {
            if(abs(seq[i]) > abs(seq[i+1]))
                possible = false;
        }


        if(possible) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

    }

    return 0;
}