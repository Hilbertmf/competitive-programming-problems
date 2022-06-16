// accepted
// https://codeforces.com/contest/1692/problem/D
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

bool isPalindrome(string& s) {
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    return tmp == s;
}

int sToTime(string& s) {
    string tmp = "";
    tmp += s[0];
    tmp += s[1];
    int hour = stoi(tmp, nullptr);
    tmp = "";
    tmp += s[3];
    tmp += s[4];
    int min = stoi(tmp, nullptr);
    return hour*60 + min;
}

string timeToS(int time) {
    int hours = time / 60;
    time -= hours * 60;
    string hourStr = to_string(hours);
    string minStr = to_string(time);

    if(hours < 10)
        hourStr = "0" + hourStr;
    if(time < 10)
        minStr = "0" + minStr;
    return hourStr + ":" + minStr;
}

void addTime(string& s, int interval) {
    int time = sToTime(s);
    time += interval;
    time %= 1440;
    s = timeToS(time);
}

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        string time;
        int interval;
        cin >> time;
        cin >> interval;
        string tmp;
        vector<string> times{time};
        int numPalindromes = 0;

        while(tmp != time) {
            if(tmp == "")
                tmp = time;
            addTime(tmp, interval);
            if(tmp != time)
                times.push_back(tmp);
        }

        for(auto &hour : times) {
            if(isPalindrome(hour))
                numPalindromes++;
        }

        cout << numPalindromes << "\n";
    }	
    
    return 0; 
}
