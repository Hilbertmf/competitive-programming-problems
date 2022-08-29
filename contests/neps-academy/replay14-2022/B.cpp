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
    int num10s = 0;
    string s;
    vector<int> grades;
    cin >> s;

    for(int i = 0; i < s.size() - 1; ++i) {
        if(s[i] != '0' && !(s[i] == '1' && s[i+1] == '0'))
            grades.push_back(s[i] - '0');
        if(s[i] == '0') num10s++;
    }
    if(s[s.size() - 1] != '0') grades.push_back(s[s.size() - 1] - '0');
    else num10s++;

    int students = num10s + grades.size();
    double tot = num10s * 10;
    for(auto &grade : grades) {
        tot += grade;
    }
    double ans = tot / students;
    printf("%.2lf\n", ans);
    return 0; 
}
