#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, h) (l + (r - l) / 2) 
#define wEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

// int grid[100][100] = {0};
// vector<vector<int>> grid(1000001, vector<int> (1000001, 0));

void initVec(vector<vector<int>> vec) { 
	for(int i = 0; i < vec.size(); i++) 
		for(int j = 0; j < vec[i].size(); j++) 
			vec[i][j] = 0;
	return; 
} 

void printArray(int r, int c, vector<vector<int>> grid) {
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}	
}

pair<int, int> getValidMid(int r, int c, int grid[][1000001]) {
	if(grid[0][0] != -1)
		return make_pair(0, 0);
	if(grid[0][c-1] != -1)
		return make_pair(0, c-1);
	if(grid[r-1][0] != -1)
		return make_pair(r-1, 0);
	if(grid[r-1][c-1] != -1)
		return make_pair(r-1, c-1);

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(grid[i][j] != -1)
				return make_pair(i, j);
		}
	}
	return make_pair(-1, -1);
	// int leftRow = 0, leftCol = 0, rightRow = r-1, rightCol = c-1;
	// int midRow = MID(leftRow, rightRow);
	// int midCol = MID(leftCol, rightCol);
	// while (grid[midRow][midCol] == -1) {
	// 	if(grid[midRow][0] == -1) {
	// 		leftRow
	// 	}
	// }
	// return make_pair(midRow, midCol);
}

int main() { 
	FASTIO; 
	//ifstream win("in.txt"); 
	//ofstream wout("out.txt"); // wout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	//int objs[num] = {0}; 
	//long long objs[num] = {0}; 

	int t;
	std::cin >> t;
	while (t--) {
		int h, w;
		string s;
		string x = "", y = "";
		std::cin >> h >> w >> s;
		
		int xmax = 0, ymax = 0;
		int numR = 0, numL = 0, numU = 0, numD = 0;
		int horizShift = 0, verticalShift = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == 'R')
				numR++;
			else if(s[i] == 'L')
				numL++;
			else if(s[i] == 'D')
				numD++;
			else if(s[i] == 'U')
				numU++;
			horizShift = numR - numL;
			verticalShift = numD - numU;

			
		}
		
		
		pair<int, int> ans = make_pair(0,0);
		

		// printArray(h, w);
	}

	return 0; 
}
