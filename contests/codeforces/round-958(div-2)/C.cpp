// ac
// https://codeforces.com/contest/1988/problem/C
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7
const long long MAXN = 1e18;

int binToDec(string& s) {
    int num = 0;
    int decimal_place = 1;
    for(int i = s.size() - 1; i >= 0; --i) {
        num += (s[i] - '0') * decimal_place;
        decimal_place *= 2;
    }
    return num;
}

string decToBin(int num) {
    string bin;
    while (num) {
        if (num & 1)
            bin += '1';
        else
            bin += '0';
        num >>= 1;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

int32_t main() {
    FASTIO;
    vector<int> power2;
    int p = 1;
    while (p <= MAXN) {
        power2.push_back(p);
        p <<= 1;
    }
    
    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;

        vector<int> sequence;
        if(binary_search(power2.begin(), power2.end(), n)) {
            sequence.push_back(n);
        }
        else {
            
            string n_bin = decToBin(n);
            int tmp = binToDec(n_bin);

            vector<string> seq_str {n_bin};
            string curr = n_bin;
            while (curr.size() == n_bin.size()) {
                curr = seq_str.back();
                int prev = binToDec(curr);
                int decimal = prev;
                if (n % 2 == 0)
                    decimal -= 2;
                else
                    decimal--;
                if (decimal == 0) break;

                curr = decToBin(decimal);

                if (curr.size() < n_bin.size()) {
                    if (seq_str.back().size() == n_bin.size()) {

                        for(int i = 0; i < power2.size() && power2[i] <= decimal + 2; ++i) {
                            if ((prev | power2[i]) == n) {
                                sequence.push_back(power2[i]);
                                break;
                            }
                        }
                    }
                    break;
                }

                for(int i = 0; i < curr.size(); ++i) {
                    if (n_bin[i] == '0' && curr[i] == '1') {
                        curr[i] = '0';
                    }
                    else if (n_bin[i] == '1' &&
                            (seq_str.back()[i] == '0' && curr[i] == '0')) {
                        
                        // go to the left searching for a 1 to make 0
                        curr[i] = '1';
                        for(int j = i - 1; j >= 0; --j) {
                            if (curr[j] == '1') {
                                curr[j] = '0';
                                break;
                            }
                        }
                    }
                }
                seq_str.push_back(curr);
            }

            for(auto &str : seq_str) {
                int num = binToDec(str);
                if (num > 0)
                    sequence.push_back(num);
            }
            sort(sequence.begin(), sequence.end());
        }

        cout << sequence.size() << "\n";
        for(int i = 0; i < sequence.size(); ++i) {
            if (i > 0) cout << " ";
            cout << sequence[i];
        }
        cout << "\n";
    }
    
    return 0;
}
