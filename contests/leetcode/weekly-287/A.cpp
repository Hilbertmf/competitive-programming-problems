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
 
int convertTime(string current, string correct) {
	int currMin = 0, correctMin = 0, diff = 0;
	currMin += ((current[0] - '0') * 10 + (current[1] - '0')) * 60;
	currMin += (current[3] - '0')*10 + current[4] - '0';
	correctMin += ((correct[0] - '0') * 10 + (correct[1] - '0')) * 60;
	correctMin += (correct[3] - '0')*10 + correct[4] - '0';

	if(correctMin < currMin) {
		diff += 1440 - currMin + correctMin;
	}
	else {
		diff = correctMin - currMin;
	}

	int ans = 0;
	ans += diff / 60;
	diff = diff % 60;
	ans += diff / 15;
	diff = diff % 15;
	ans += diff / 5;
	diff = diff % 5;
	ans += diff / 1;
	diff = diff % 1;

	return ans;
}

int main() { 
	FASTIO;
	string curr, correct;
	std::cin >> curr >> correct;
	
	cout << convertTime(curr, correct);
	return 0; 
}
