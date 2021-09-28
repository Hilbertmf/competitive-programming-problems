#include <bits/stdc++.h>

using namespace std;

int main() {
	// naive solution
  int cases;
  cin >> cases;
  while(cases--)
  {
    int num_snakes, num_queries, count=0;
    cin >> num_snakes >> num_queries;
    int snakes[100010] = {0};
    int snakes_aux[100010] = {0};
    int prefix[100010] = {0};
    int query = 0;
    for(int i=0;i<num_snakes;i++)
    {
      cin >> snakes[i];
      snakes_aux[i] = snakes[i];
      prefix[i] = (i > 0) ? snakes[i] + prefix[i-1] : snakes[i];
    }
    sort(snakes_aux, snakes_aux + num_snakes, greater<int>());
    for(int i=0;i<num_queries;i++)
    {
      cin >> query;
      count = 0;
      for(int j=0;j<num_snakes;j++)
      {
        if(snakes_aux[j] >= query){
          count++;
        }
          
        else {
          if(snakes_aux[j] + (num_snakes - 1 - j) >= query)
          {
            j += query - snakes_aux[j];
            count++;
          }
        }
      }
      printf("%d\n",count);
    }
  }
	
	return 0;
}