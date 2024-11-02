#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int firstGreater(int t, int mul) {
    return (mul * (t / mul)) + mul;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<int> x(n - 1);
        for(auto &num : x) cin >> num;
        
        vector<int> a(n);
        a[0] = x[0] + 503;

        for(int i = 1; i < n; ++i) {
            a[i] = 0;
            a[i] = firstGreater(x[i], a[i - 1]);
            a[i] -= x[i - 1];

            if (a[i] < 1 || a[i] % a[i - 1] != x[i - 1]) {
                a[i] = firstGreater(x[i], a[i - 1]);
                a[i] += x[i - 1];

            }

        }


        for(auto &num : a) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}



class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = nullptr;
        while (node->next != nullptr) {
            int tmp = node->val;
            node->val = node->next->val;
            node->next->val = tmp;
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
        delete node;
    }
};