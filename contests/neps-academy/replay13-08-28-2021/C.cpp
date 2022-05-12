#include <bits/stdc++.h> 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;


int combinationNChooses2(int n)
{
  return (n * (n-1)) / 2;
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int main() 
{ 
	int num_cards;
  int count = 0;
  scanf("%d",&num_cards);
  int cards[num_cards+10] = {0};
  int prefix_sum[num_cards+10] = {0};
  int mods[num_cards+10] = {0};
  int hash[30] = {0};
  hash[0] = 1;
  for (int i = 0; i < num_cards; i++)
  {
    scanf("%d",&cards[i]);
    prefix_sum[i] = (i > 0) ? cards[i] + prefix_sum[i-1] : cards[i];
    mods[i] = prefix_sum[i] % 21;
  }
  
  // printArray(mods, num_cards);

  for (int i = 0; i < num_cards; i++)
  {
    hash[mods[i]]++;
    // printf("log 1 count = %d\n", count);
  }

  // printf("hash:\n");
  // printArray(hash, 21);

  for (int i = 0; i < 21; i++)
  {
    if(hash[i] >= 2) {
      count += combinationNChooses2(hash[i]);
      // printf("log 2 count = %d\n", count);
    }
  }

  
  printf("%d\n",count);
	return 0; 
}

// range(i, j)
// prefix(j) - prefix(i-1)

// mods[j] == mods[i-1] 

// mods [0,0,3,3,3,4,10]

// sort(mods, mods + num_cards);
  // int equalElements = 1;
  // for (int i = 0; i < num_cards; i++)
  // {
  //   if(mods[i] == 0)
  //     count++;
  //   if(mods[i] == mods[i+1] && i < num_cards - 1)
  //     equalElements++;
  //   else
  //   {
  //     if(equalElements > 1)
  //       count += combinationNChooses2(equalElements);
  //     equalElements = 1;
  //   }
  // }