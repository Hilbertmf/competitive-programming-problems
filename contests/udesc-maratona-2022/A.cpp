// accepted
// https://codeforces.com/group/4QT6JKdRZ8/contest/387588/problem/A
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
 
int main() { 
    FASTIO;
    double radius, distance, fuel;
    cin >> radius >> distance >> fuel;

    double finalDist = radius * acos(1 - (distance * distance) / (2 * radius * radius));
    bool possible = fuel >= (finalDist * 2);
    
    if(possible)
        cout << "possivel" << "\n";
    else
        cout << "impossivel" << "\n";
    
    return 0; 
}
