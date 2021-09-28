#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
 
using namespace std;

/*
strategies for solving:
Greedy: Repeatedly pairing the two remaining students with the
shortest separating distances results in Wrong Answer

Complete Search w/ backtracking: Using recursive backtracking (Section 3.2) and trying
all possible pairings yields Time Limit Exceeded

Real solution: minimum weight perfect matching on a small general weighted graph

Alternate solution: Dynamic programming w/ bitmask that describes a matching status, 
and matching unmatched students i and j will turn on two bits i and j in the bitmask
*/
 
float calc_dist(int x1, int y1, int x2, int y2)
{
  int d1, d2;
  d1 = abs(x1-x2);
  d2 = abs(y1-y2);
  int res = d1*d1 + d2*d2;
  return sqrt(res);
}

int main() 
{ 
	int n;
  scanf("%d", &n);
  
  int houses[20][2];
  int x[20] = {0};
  int y[20] = {0};

  for (int i = 0; i < n*2; i++)
  {
    int aux1, aux2;
    scanf("%d %d", &aux1, &aux2);
    houses[i][0] = aux1;
    houses[i][1] = aux2;
    x[i] = aux1;
    y[i] = aux2;
  }
  
  for (int i = 0; i < n*2; i++)
  {
    for (int j = i; j < n*2; j++)
    {
      /* code */
    }
    
  }
  

  printf("dist h1 / h2: %f\n", calc_dist(x[0],y[0],x[1],y[1]));
  printf("dist h1 / h3: %f\n", calc_dist(x[0],y[0],x[2],y[2]));
	printf("dist h1 / h4: %f\n", calc_dist(x[0],y[0],x[3],y[3]));
	return 0; 
}
