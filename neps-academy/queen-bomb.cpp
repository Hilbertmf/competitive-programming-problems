#include <bits/stdc++.h> 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;
 
int main() 
{ 
	int rows,cols;
  char grid[110][110];
  int x_bomb,y_bomb, count=0;
	scanf("%d %d", &rows, &cols);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> grid[i][j];
      if(grid[i][j] == '*')
      {
        x_bomb = i;
        y_bomb = j;  
      }  
    }
  }
  
	for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (grid[i][j] == 'P')
      {
        //same col, row or diagonal
        if ((i == x_bomb || j == y_bomb) || (abs(x_bomb - i) == abs(y_bomb - j)))
          count++;
      }
    }
  }
  printf("%d\n",count);
	return 0; 
}
