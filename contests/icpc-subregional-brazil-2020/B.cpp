#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;

int main() 
{ 
	int noShips;
	int isVertical, length, row, col;
	cin >> noShips;
	int grid[10][10] = {0};
	bool isValid = true;
	for (int i = 0; i < noShips; i++) {
		cin >> isVertical >> length >> row >> col;
		row--;
		col--;

		if(isVertical == 1) {
			if(row + length - 1 <= 9) {
				for (int j = 0; j < length; j++) {
					grid[row+j][col]++;
				}
			}
			else {
				printf("N\n");
				return 0;
			}
		}
		else {
			if (col + length - 1 <= 9){
				for (int j = 0; j < length; j++) {
					grid[row][col+j]++;
				}
			}
			else {
				printf("N\n");
				return 0;
			}
		}

	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if(grid[i][j] > 1)
				isValid = false;
		}
	}
	if(isValid)
		printf("Y\n");
	else
		printf("N\n");
	
	
	
	return 0; 
}
