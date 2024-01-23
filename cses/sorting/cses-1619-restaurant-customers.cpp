// https://cses.fi/problemset/task/1619
// time: O(nlogn)
// space: O(n)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
    FASTIO;

    int num_customers, arrival_time, leave_time;
    cin >> num_customers;
    vector<int> times(num_customers * 2);
    unordered_multiset<int> arriving;
    unordered_multiset<int> leaving;
    arriving.reserve(num_customers);
    leaving.reserve(num_customers);
    for(int i = 0; i < num_customers * 2; i += 2) {
        cin >> arrival_time >> leave_time;
        times[i] = arrival_time;
        times[i + 1] = leave_time;
        arriving.insert(arrival_time);
        leaving.insert(leave_time);
    }
    sort(times.begin(), times.end());
    
    int max_customers = 1;
    int curr_customers = 0;
    for(int i = 0; i < times.size(); ++i) {
        curr_customers += arriving.count(times[i]);
        max_customers = max(max_customers, curr_customers);
        curr_customers -= leaving.count(times[i]);
    }
    
    cout << max_customers << "\n";

    return 0;
}
