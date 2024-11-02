#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

bool is_valid_number(const string& s) {
    char mid = s[s.size() / 2];
    int count_mid = 0;
    for (char c : s) {
        if (c == mid) count_mid++;
        if (c < '0' || c > '9') return false;
    }

    if (count_mid != 1) return false;

    int i = 1;
    for (; i <= s.size() / 2; ++i) {
        if (s[i] < s[i - 1]) return false;
    }
    for (i = s.size() / 2 + 1; i < s.size(); ++i) {
        if (s[i] > s[i - 1]) return false;
    }
    return true;
}

void genSecHalf(string& cur, int pos, int sz, unordered_set<string>& peaks, char last_char) {
    if (pos == sz) {
        peaks.insert(cur);
        return;
    }
    
    for (char c = last_char; c >= '1'; --c) {
        cur += c;
        genSecHalf(cur, pos + 1, sz, peaks, c);
        cur.pop_back();  
    }
}

void genPeaks(string& cur, int pos, int sz, unordered_set<string>& peaks, char last_char) {
    if (pos == sz / 2) {
        char mid = last_char + 1;
        if (pos == 0) mid = last_char;
        for (; mid <= '9'; ++mid) {  
            string tmp = cur + mid;  
            genSecHalf(tmp, pos + 1, sz, peaks, (char)(mid - 1));  
        }
        return;
    }

    for (char c = last_char; c <= '9'; ++c) {  
        cur += c;
        genPeaks(cur, pos + 1, sz, peaks, c);  
        cur.pop_back();  
    }
}

int32_t main() {
    FASTIO;
    int t, tcase = 1;
    cin >> t;

    while (t--) {
        int a, b, m, ans = 0;
        cin >> a >> b >> m;

        string s_a = to_string(a);
        string s_b = to_string(b);

        unordered_set<string> peaks;
        int sz = s_a.size();
        if (sz % 2 == 0) sz++;  

        if (sz <= s_b.size() && sz <= 18) {
            while (sz <= s_b.size() && sz <= 18) {
                for (char c = '1'; c <= '9'; ++c) {
                    string current = "";
                    genPeaks(current, 0, sz, peaks, c);  
                }
                sz += 2;
            }
        }

        for (auto& s : peaks) {
            if (!is_valid_number(s)) continue;
            if (s.size() > 18) continue;

            int num = stoll(s);
            if (num < a || num > b) continue;
            if (num % m != 0) continue;

            ans++;
        }

        cout << "Case #" << tcase << ": ";
        cout << ans << "\n";
        tcase++;
    }

    return 0;
}
