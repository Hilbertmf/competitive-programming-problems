// https://codeforces.com/contest/1611/problem/C
// accepted
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
 
void printPermutation(deque<int> permutation) {
	while(!permutation.empty()) {
		std::cout << permutation.front();
		if(permutation.size() > 1) std::cout << " ";
		permutation.pop_front();
	}
}

int main() {
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		int length;
		std::cin >> length;
		vector<int> a(length);
		deque<int> finalPerm;
		for(int i = 0; i < length; i++) {
			std::cin >> a[i];
			finalPerm.push_back(a[i]);
		}

		if(length == 1) {
			std::cout << a[0] << std::endl;
		}
		else {
			deque<int> perm;

			// here we undo the operations to find our initial permutation
			int last = a[a.size()-1];
			perm.push_back(last);
			int left = 0, right = a.size() - 2;
			while(left <= right) {
				if(a[left] <= a[right]) {
					perm.push_front(a[left]);
					left++;
				}
				else {
					perm.push_back(a[right]);
					right--;
				}
			}
			// store our permutation
			deque<int> answerPerm = perm;
			deque<int> resultPerm;

			// now we do the operations
			// trying to get the same result of the test case
			while(!perm.empty()) {
				int front = perm.front(), back = perm.back();
				if(front < back) {
					resultPerm.push_front(front);
					perm.pop_front();
				}
				else {
					resultPerm.push_back(back);
					perm.pop_back();
				}
			}
			// this handles the final step:
			// whether the final num is put at front or back
			if(resultPerm.front() != finalPerm.front()) {
				resultPerm.pop_back();
				finalPerm.pop_front();
			}
			if(resultPerm == finalPerm)
				printPermutation(answerPerm);
			else 
				std::cout << -1;
			
			cout << "\n";
		}
	}
	return 0; 
}
