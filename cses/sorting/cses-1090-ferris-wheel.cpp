// https://cses.fi/problemset/task/1090/
// time: O(n)
// space: O(n)
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e9

int main() {
    FASTIO;
   
    int children, max_weight;
    cin >> children >> max_weight;
    vector<int> weights(children);
    for(int &weight : weights) cin >> weight;

    sort(weights.begin(), weights.end());

    int left = 0, right = children - 1;
    int num_gondolas = 0;
    for(; left < children - 1 && left < right; ++left) {
        
        while (left < right &&
            weights[left] + weights[right] > max_weight) {
            right--;
        }

        if(left < right &&
            weights[left] + weights[right] <= max_weight) {

            weights[left] = INF;
            weights[right] = INF;
            num_gondolas++;
            right--;
        }
    }

    for(int i = 0; i < children; ++i) {
        if(weights[i] <= max_weight)
            num_gondolas++;
    }
    
    cout << num_gondolas << "\n";

    return 0;
}

