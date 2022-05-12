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
void initArray(int arr[], int length, int val) { 
	for (int i = 0; i < length; i++) 
		arr[i] = val; 
	return; 
} 
 
void solve() { 
 
} 
 
int solve(int arg) { 
 
} 
 
int main() { 
	FASTIO; 
	//ifstream cin("in.txt"); 
	//ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	// long long numPeople, minClassify, ans; 

	int numPeople, minClassify, ans = 0; 
	cin >> numPeople >> minClassify; 
	int people[1010] = {0}; 
	//long long people[numPeople, minClassify] = {0}; 


	for(int i = 0; i < numPeople; i++) { 
		cin >> people[i]; 
	} 


	sort(people, people+numPeople, greater<int>());

	for(int i = 0; i < minClassify; i++) { 
		ans++;
		if(i == minClassify - 1 && minClassify < numPeople) {
			int lastPts = people[i];
			i++;
			while(people[i] == lastPts) {
				ans++;
				i++;
			}
		}
	} 

	cout << ans << endl; 
	//printf("%d", ans); 
	return 0; 
}
