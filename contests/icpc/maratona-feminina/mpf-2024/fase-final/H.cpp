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

    int n, k;
    cin >> n >> k;

    vector<int> arrivals(n);
    vector<int> times(n);
    vector<pair<int, int>> tmp(n);
    priority_queue<pair<int, int>> atendimento;
    priority_queue<pair<int, int>> fila_espera;
    int ans = 1;
    int curr_time = arrivals[0];
    for(int i = 0; i < n; ++i) {
        cin >> arrivals[i] >> times[i];
        tmp[i] = {arrivals[i], times[i]};
        if (i < k) {
            int chegada = arrivals[i] + times[i];
            atendimento.push({-chegada, i});
        }
        if (i > 0 && arrivals[i] < arrivals[0] + times[0]) {
            ans++;
            fila_espera.push({-arrivals[i], i});
        }
    }

    curr_time = -atendimento.top().first;
    for(int i = k; i < n; ++i) {
        
        while (i < n && !atendimento.empty() && arrivals[i] > curr_time) {
            int curr_time = -(atendimento.top().first);
            int idx = atendimento.top().second;
            atendimento.pop();

            ans = max(ans, (long long)(atendimento.size() + fila_espera.size()));
            if(fila_espera.empty()) {
                atendimento.push({-arrivals[i], i});                
            }
            else {
                int j = fila_espera.top().second;
                int arrival = -fila_espera.top().first - times[j];
                fila_espera.pop();
                atendimento.push({arrival, j});
            }

        }

    }




    for(int i = 0; i < length; ++i) {
        
    }


    int left = 0, right = 0;

    while (left < n) {
        int people = 1;
        curr_time += times[left];
        auto it = upper_bound(arrivals.begin(), arrivals.end(), curr_time);
        if (it != arrivals.begin())
            --it;
        
        right = it - arrivals.begin();
        DEBUG(right);

        int diff = 0;
        if (right > left)
            diff = (right - left);


        if (diff > k) {

        }
        ans = max(ans, people);
        left++;
    }

    cout << ans << "\n";

    return 0;
}
