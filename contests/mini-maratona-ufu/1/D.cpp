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

std::tm dateToTime(string date) {
	int year = stoi(date.substr(0, 4));
	int month = stoi(date.substr(5, 7));
	int day = stoi(date.substr(8));
	std::tm t = {0};
	t.tm_year = year;
	t.tm_mon = month;
	t.tm_mday = day;
	return t;
}

int main() { 
	FASTIO;
	int n;
	cin >> n;

	while(n--) {
		string date1, date2;
		tm t = {};
		cin >> date1 >> date2;

		std::tm time1 = dateToTime(date1);
		std::tm time2 = dateToTime(date2);

		std::time_t t1 = mktime(&time1);
		std::time_t t2 = mktime(&time2);

		time_t diff = t2 - t1;
		diff /= 86400; // days
		diff = abs(diff);
		
		cout << diff << "\n";
	}
		
	return 0; 
}
