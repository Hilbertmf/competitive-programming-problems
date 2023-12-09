#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<int> zFuncInefficient(string& txt, string& pat) {
    string s = pat;
    s += '$';
    s += txt;
    vector<int> z(s.size());

    for(int i = pat.size() + 1; i < s.size(); ++i) {
        int j = z[i] + i;
        
        while (j < s.size() &&
        s[z[i]] == s[j]) {
            z[i]++;
            j = z[i] + i;
        }
        
    }

    return z;
}

int32_t main() {
    FASTIO;
    
    vector<string> lines;
    string s;

    vector<string> nums {"one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine"};

    while (getline(cin, s)) {
        lines.push_back(s);
    }

    int ans = 0;

    for(string& line : lines) {
        int cali = 0;
        vector<pair<int, int>> num_location;

        int digit = 1;
        for(string num : nums) {
            vector<int> z_array = zFuncInefficient(line, num);

            for(int i = num.size() + 1; i < z_array.size(); ++i) {
                if(z_array[i] == num.size()) {
                    num_location.push_back({i - (num.size() + 1), digit});
                    break;
                }
            }
            for(int i = z_array.size() - 1; i >= num.size() + 1; --i) {
                if(z_array[i] == num.size()) {
                    num_location.push_back({i - (num.size() + 1), digit});
                    break;
                }
            }
            
            digit++;
        }
        
        sort(num_location.begin(), num_location.end());

        for(int i = 0; i < line.size(); ++i) {
            if(line[i] >= '0' && line[i] <= '9') {
                if(num_location.empty() || i < num_location[0].first)
                    cali += (line[i] - '0') * 10;
                else
                    cali += num_location[0].second * 10;
                
                break;
            }
        }

        if(cali == 0) cali += num_location[0].second * 10;

        for(int i = line.size() - 1; i >= 0; --i) {
            if(line[i] >= '0' && line[i] <= '9') {
                if(num_location.empty() || i > num_location.back().first)
                    cali += (line[i] - '0');
                else
                    cali += num_location.back().second;
                
                break;
            }
        }

        if(cali % 10 == 0) cali += num_location.back().second;

        ans += cali;
    }

    cout << ans << "\n";

    return 0;
}
