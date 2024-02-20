#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

string decimalToBinary(int n) {
    string binary;
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

int binaryToDecimal(const string& binary) {
    int decimal = 0;
    int power = 0;
    for (int i = binary.size() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += std::pow(2, power);
        }
        power++;
    }
    return decimal;
}

string negateBits(const std::string& binary) {
    string result;
    for (char bit : binary) {
        if (bit == '0') {
            result += '1';
        } else {
            result += '0';
        }
    }

    while (result.size() < 31) {
        result = '1' + result;
    }
    return result;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<int> nums(n);
        map<int, int> count;
        map<int, int> count2;
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
            count[nums[i]]++;
            count2[nums[i]]++;
        }
        int groups = 0;

        for(auto it = count.begin(); it != count.end(); ++it) {
            int key = it->first;
            int val = it->second;
            int val2 = count2[key];
            string bin = decimalToBinary(key);
            string negated_str = negateBits(bin);
            int neg = binaryToDecimal(negated_str);

            if(count.find(neg) != count.end() && count[neg] > 0) {
                count2[neg] = max(0ll, count[neg] - val);
            }
            groups += val2;


        }

        cout << groups << "\n";

    }
    
    return 0;
}
