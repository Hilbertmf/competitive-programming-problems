#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int num_elems, num_queries, begin, end;
  int numbers[100010] = {0};
  int prefix_sum[100010] = {0};

	scanf("%d", &num_elems);

  while(num_elems--)
  {
    scanf("%d", &numbers[i]);
    prefix_sum[i] = (i > 0) ? numbers[i] + prefix_sum[i-1] : numbers[i];
  }
  scanf("%d", &num_queries);
  while(num_queries--)
  {
    scanf("%d %d", &begin, &end);
    int ans = (begin > 0) ? prefix_sum[end] - prefix_sum[begin-1] : prefix_sum[end];
    printf("%d\n", ans);
  }
	return 0; 
}
