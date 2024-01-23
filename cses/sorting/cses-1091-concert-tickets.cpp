// https://cses.fi/problemset/task/1091/
// time: O(nlogn)
// space: O(n)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int main() {
    FASTIO;
 
    int num_tickets, num_people, ticket;
    cin >> num_tickets >> num_people;
    multiset<int> prices;
    vector<int> people(num_people);
    for(int i = 0; i < num_tickets; ++i) {
        cin >> ticket;
        prices.insert(ticket);
    }
    for(auto &person : people) cin >> person;
 
    for(int i = 0; i < num_people; ++i) {
 
        auto it = prices.lower_bound(people[i]);
        if(prices.empty() ||
        (it != prices.end() && *it > people[i] && it == prices.begin())) {
            cout << "-1\n";
            continue;
        }
        else if(it == prices.end() || *it > people[i]) {
            --it;
        }
        
        cout << *it << "\n";
        prices.erase(it);
 
    }
    
 
    return 0;
}