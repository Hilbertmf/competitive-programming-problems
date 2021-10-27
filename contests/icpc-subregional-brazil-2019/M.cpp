#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (int)1e9 
#define LONGINF (long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const long MOD = 1000000007; // 10^9 - 7 
void initArray(long arr[], long length, long val) { 
	for (long i = 0; i < length; i++) 
		arr[i] = val; 
	return; 
} 

/*
	isValid returns if we can eat each and all popcorns
	in all bags using at most C competitors in given time T
*/

bool isValid(long time, long numBags, long bags[], long numCompetitors) { 
	long amountEaten = 0;
	long competitor = 1;
	for (long i = 0; i < numBags; i++) {
		// if its bigger than we need a greater time
		if(bags[i] > time)
			return false;
		// test if current competitor can eat bag in given time
		if(amountEaten + bags[i] <= time) 
			amountEaten += bags[i];
		else { // go to next competitor
			competitor++;
			amountEaten = bags[i];
			if(competitor > numCompetitors) // we have used all competitors
				return false;
		}
	}
	return true;
} 

/* 
	if isValid(x) == true then isValid(x+1) == true
	We want to find the first x that returns true,
	that would be the minimum time to eat all popcorns.
	Our isValid method is a monotonic function so we can
	do binary search on all times available to find the 
	minimum time that returns true
*/

bool isMinTime(long time, long numBags, long bags[], long numCompetitors) {
	return isValid(time, numBags, bags, numCompetitors) && 
				 !isValid(time - 1, numBags, bags, numCompetitors);	
}

long binarySearch(long numBags, long bags[], long numCompetitors, long rate) { 
	long left = 1;
	long right = (long)1e9 + 1;
	// edge cases
	if(isValid(left, numBags, bags, numCompetitors))
		return left;
	if(isMinTime(right, numBags, bags, numCompetitors))
		return right;
	
	long mid = left + (right - left) / 2;

	while(!isMinTime(mid, numBags, bags, numCompetitors)) {
		if(isValid(mid, numBags, bags, numCompetitors))
			right = mid;
		else
			left = mid;
		mid = left + (right - left) / 2;
	}
	return CEILDIVISION(mid, rate);
}
 
int main() { 
	FASTIO; 
	// ifstream cin("in.txt"); 
	// ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	long numBags, numCompetitors, rate; // rate is the num of popcorns a single competitor can eat
	
	cin >> numBags >> numCompetitors >> rate;
	long bags[100010];
	
	for (long i = 0; i < numBags; i++)
		cin >> bags[i];
	
	long time = binarySearch(numBags,bags,numCompetitors,rate);
	cout << time << endl;
	
	return 0; 
}
