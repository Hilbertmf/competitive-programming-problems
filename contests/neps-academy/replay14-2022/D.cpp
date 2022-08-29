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
    string num;
    cin >> num;
    bool found = true;
    unordered_map<char, int> mp;
    mp.reserve(10);
    for(auto c : num) {
        mp[c]++;
        if(mp[c] > 2) found = false;
    }

    if(found) {
        cout << num << "\n";
    }
    else {
        vector<pair<int, int>> digitIndices(10, {-1, -1});
        bool flag = false;

        for(int i = 0; i < num.size(); ++i) {
            // digit allowed
            if(i == num.size() - 1) {
            }
            if(i <= digitIndices[num[i] -'0'].second ||
            digitIndices[num[i] - '0'].first == -1 ||
            digitIndices[num[i] - '0'].second == -1) {
                if(digitIndices[num[i] - '0'].first == -1 ||
                i < digitIndices[num[i] - '0'].first) {
                    digitIndices[num[i] - '0'].second = digitIndices[num[i] - '0'].first;
                    digitIndices[num[i] - '0'].first = i;
                }
                else
                    digitIndices[num[i] - '0'].second = i;
            }
            else {
                bool canInsert = false;

                for(int digit = num[i] - '0' - 1; digit >= 0; --digit) {
                    if(i == num.size() - 1) {
                    }
                    if(digitIndices[digit].second == -1 ||
                    digitIndices[digit].first == -1 ||
                    i <= digitIndices[digit].second) {
                        if(digitIndices[digit].first == -1 ||
                        i < digitIndices[digit].first) {
                            digitIndices[digit].second = digitIndices[digit].first;
                            digitIndices[digit].first = i;
                        }
                        else
                            digitIndices[digit].second = i;

                        if(i == digitIndices[num[i] - '0'].first) {
                            digitIndices[num[i] - '0'].first = digitIndices[num[i] - '0'].second;
                            digitIndices[num[i] - '0'].second = -1;
                        }
                        else if(i == digitIndices[num[i] - '0'].second) {
                            digitIndices[num[i] - '0'].second = -1;
                        }
                        
                        num[i] = digit + '0';
                        
                        if(!flag) {
                            for(int j = i + 1; j < num.size(); ++j) {
                                num[j] = '9';
                            }
                            for(int w = 0; w < digitIndices.size(); ++w) {
                                if(digitIndices[w].first > i) {
                                    digitIndices[w].first = -1;
                                    digitIndices[w].second = -1;
                                }
                                else if(digitIndices[w].second > i)
                                    digitIndices[w].second = -1;
                            }
                        }
                        canInsert = true;
                        flag = true;
                        break;
                    }
                }

                if(!flag) {
                    int k = i - 1;
                    for(; k >= 0; --k) {
                        
                        for(int digit = num[k] - '0' - 1; digit >= 0; --digit) {
                            
                            if(k <= digitIndices[digit].second ||
                            digitIndices[digit].second == -1 ||
                            digitIndices[digit].first == -1) {
                                if(digitIndices[digit].first == -1 ||
                                k < digitIndices[digit].first) {
                                    digitIndices[digit].second = digitIndices[digit].first;
                                    digitIndices[digit].first = k;
                                }
                                else
                                    digitIndices[digit].second = k;
                                
                                if(k == digitIndices[num[k] - '0'].first) {
                                    digitIndices[num[k] - '0'].first = digitIndices[num[k] - '0'].second;
                                    digitIndices[num[k] - '0'].second = -1;
                                }
                                else {
                                    digitIndices[num[k] - '0'].second = -1;
                                }
                                num[k] = digit + '0';
                                
                                for(int j = k + 1; j < num.size(); ++j) {
                                    num[j] = '9';
                                }
                                for(int w = 0; w < digitIndices.size(); ++w) {
                                    if(digitIndices[w].first > k) {
                                        digitIndices[w].first = -1;
                                        digitIndices[w].second = -1;
                                    }
                                    else if(digitIndices[w].second > k)
                                        digitIndices[w].second = -1;
                                }
                                canInsert = true;
                                flag = true;
                                break;
                            }
                        }

                        if(flag) break;
                    }
                    i = k;

                }
            }
        }

        int i = 0;
        while(i < num.size() && num[i] == '0') i++;
        
        num = num.substr(i);
        
        cout << num << "\n";
    }

    
    return 0; 
}
