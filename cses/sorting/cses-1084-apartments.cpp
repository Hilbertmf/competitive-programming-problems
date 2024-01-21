// https://cses.fi/problemset/task/1084/
// time: O(nlogn)
// space: O(n)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;

    int num_people, num_apt, diff;
    cin >> num_people >> num_apt >> diff;
    vector<int> people(num_people);
    vector<int> apartments(num_apt);
    for(auto &person : people) cin >> person;
    for(auto &apt : apartments) cin >> apt;
    
    sort(people.begin(), people.end());
    sort(apartments.begin(), apartments.end());
    
    int count = 0;
    int left = 0;
    for(int person : people) {
        int low = max(person - diff, 0);
        int high = person + diff;
        auto apartment_it = lower_bound(apartments.begin() + left, apartments.end(), low);
        if(apartment_it != apartments.end() && *apartment_it <= high) {
            count++;
            left = apartment_it - apartments.begin() + 1;
        }
        
        if(left >= num_apt || apartment_it == apartments.end())
            break;
    }

    cout << count << "\n";

    return 0;
}
