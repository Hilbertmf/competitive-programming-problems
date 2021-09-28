#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int n, p, q, r;
  scanf("%d %d %d %d", &n, &p, &q, &r);
  int values[n+10] = {0};
  int prefix_sum[n+10] = {0};
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &values[i]);
    prefix_sum[i] += (i > 0) ? values[i] + prefix_sum[i-1] : values[i];
  }
  
	
 
	printf("%d\n", prefix_sum[n-1]);
 
	return 0; 
}
