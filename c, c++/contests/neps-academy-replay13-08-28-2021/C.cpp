#include <bits/stdc++.h> 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;


// optimal solution
// Complexity: O(n)
int subArraysDivisibleByK(int arr[], int k, int num_cards)
{
  // auxiliary hash array to count frequency of remainders
  int aux_mod[k] = {0};

  int cumulative_sum = 0;
  for (int i = 0; i < num_cards; i++)
  {
    cumulative_sum += arr[i];
    aux_mod[((cumulative_sum % k) + k) % k]++;
    // aux_mod[cumulative_sum % k] += 1;
  }

  int result = 0;

  for (int i = 0; i < k; i++)
  {
    if (aux_mod[i] > 1)
      result += (aux_mod[i] * (aux_mod[i] - 1) ) / 2;
  }

  result += aux_mod[0];
  return result;
}

int main() 
{ 
	int num_cards, count=0, accumulator;
  int k = 21;
  int cards[1000010];
	scanf("%d", &num_cards);

  for (int i = 0; i < num_cards; i++)
  {
    scanf("%d", &cards[i]);
  }

  // naive solution
  // Complexity: O(n²)


  for (int i = 0; i < num_cards; i++)
  {
    if(cards[i] % k == 0)
      count++;
    accumulator = cards[i];
    for (int j = i+1; j < num_cards; j++)
    {
      accumulator += cards[j];
      if(accumulator % k == 0)
        count++;
    }
  }
 
	// printf("%d\n", count);
  printf("%d\n", subArraysDivisibleByK(cards, k, num_cards));
 
	return 0; 
}
