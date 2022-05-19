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

void calcNum0sAnd1s(string& s, int curr, int& currNum0s, int& currNum1s, int num1s, int& removed1s, vector<int>& idxsOf0, int leftIdx) {

	auto rightItr = lower_bound(idxsOf0.begin(), idxsOf0.end(), curr);
	auto leftItr = lower_bound(idxsOf0.begin(), idxsOf0.end(), leftIdx);
	currNum0s = rightItr - leftItr + 1;
	currNum1s = (curr - leftIdx + 1) - currNum0s;
	removed1s = num1s - currNum1s;

}

int binarySearch(int start, int end, int num1s, string& s, vector<int>& idxsOf0, int leftIdx) {
	int mid = MID(start, end);
	int currNum0s, currNum1s;
	int removed1s;
	calcNum0sAnd1s(s, mid, currNum0s, currNum1s, num1s, removed1s, idxsOf0, leftIdx);

	currNum1s = (mid - leftIdx + 1) - currNum0s;
	removed1s = num1s - currNum1s;
	int newCost = max(currNum0s, removed1s);

	while(start < end) {
		if(currNum0s == removed1s) {
			return newCost;	
		}
		if(currNum0s > removed1s) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
		mid = MID(start, end);
		
		calcNum0sAnd1s(s, mid, currNum0s, currNum1s, num1s, removed1s, idxsOf0, leftIdx);
		newCost = min(newCost, max(currNum0s, removed1s));
	}

	return newCost;
}

int main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int num0s = 0;
		int num1s = 0;
		vector<int> idxsOf0;

		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '0') {
				idxsOf0.push_back(i);
				++num0s;
			}
			else {
				++num1s;
			}
		}

		// int bs = binarySearch(0, s.size(), num1s, s, idxsOf0, 0);
		// DEBUG(bs);
		// DEBUG(totalCost);
		// int cost = min(cost, bs);
		int i;
		for(i = 0; i < s.size() && s[i] == '0'; ++i) {}
		
		if(i > 0) num0s -= i;

		int size, count = 0;
		for(size = s.size() - 1; size >= 0 && s[size] == '0'; --size, ++count) {}

		if(size != s.size() - 1) num0s -= count;

		int totalCost;
		if(num0s == s.size() || num0s <= 0)
			totalCost = 0;
		else
			totalCost = num0s;


		DEBUG(num1s);
		DEBUG(num0s);
		for(i; num0s < s.size() && i <= size; ++i) {
			DEBUG(i);
			DEBUG(size);
			string curr;
			curr += s[i];
			int currNum0s = (s[i] == '0') ? 1 : 0;
			int currNum1s = (s[i] == '1') ? 1 : 0;
			int cost = max(currNum0s, num1s - currNum1s);

			DEBUG(cost);
			cost = min(cost, binarySearch(i, size, num1s, s, idxsOf0, i));
			totalCost = min(cost, totalCost);
		}
		

		cout << totalCost << endl;
	}	
	
	return 0; 
}
