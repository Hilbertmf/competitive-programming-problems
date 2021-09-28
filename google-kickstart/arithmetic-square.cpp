#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

// is arithmetic progression
bool is_ap(int n1, int n3)
{
  return abs(n3-n1) % 2 == 0;
}

void count_ap(long int n1, long int n2, long int n3, int &count)
{
  if((n1 - n2) == (n2 - n3))
  {
    count++;
    return;
  }
  return;
}

void possible_center(long int n1, long int n2, long int &center)
{
  printf("center = %ld\n", center);
  if (is_ap(n1, n2))
  {
    center = (n1-n2)/2 + n2;
    return;
  }
  return;
}

int most_frequent(long int arr[], long int n)
{
  sort(arr, arr + n);
  int max_count = 1, res = arr[0], curr_count = 1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == arr[i-1])
    {
      curr_count++;
    } else {
      if (curr_count > max_count)
      {
        max_count = curr_count;
        res = arr[i-1];
      }
      curr_count = 1;
    }
    
  }
  
  // If last element is most frequent
  if (curr_count > max_count)
  {
    max_count = curr_count;
    res = arr[n - 1];
  }
  return res;
}

int main() 
{ 
	int times;
  int count = 0;
  
  scanf("%d", &times);

  for (int t = 0; t < times; t++)
  {
    long int grid[3][3] = {0};
    count = 0;
    // instead of using array use a pair with int and bool
    int long center[4];

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (i == 1 && j == 1)
        {
          scanf("%ld", &grid[i][j+1]);
          break;
        } else {
          scanf("%ld", &grid[i][j]);
        }
      }
    }

    // rows
    count_ap(grid[0][0], grid[0][1], grid[0][2], count);
    count_ap(grid[2][0], grid[2][1], grid[2][2], count);

    // cols
    count_ap(grid[0][0], grid[1][0], grid[2][0], count);
    count_ap(grid[0][2], grid[1][2], grid[2][2], count);
  
    possible_center(grid[1][0], grid[1][2], center[0]);
    possible_center(grid[0][1], grid[2][1], center[1]);
    possible_center(grid[2][0], grid[0][2], center[2]);
    possible_center(grid[0][0], grid[2][2], center[3]);
    
    long int most_freq_num = most_frequent(center, 4);
    for (int i = 0; i < 4; i++)
    {
      printf("freq:%ld\n",most_freq_num);
      if (center[i] == most_freq_num)
      {
        count++;
      }  
    }
    
    printf("Case #%d: %d\n", t+1, count);
  }
    
	return 0; 
}
