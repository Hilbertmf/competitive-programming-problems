#include <bits/stdc++.h> 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;

int nth_diagonal;

unsigned long long int fib(int n)
{
  //array to store fib numbers:
  unsigned long long int memo[n+10];
  int i;
  memo[0] = 0;
  memo[1] = 1;

  for (i = 2; i <= n; i++)
  {
    memo[i] = memo[i-1] + memo[i-2];
  }
  return memo[n];
}

int main()
{ 
	
  cin >> nth_diagonal;
  // cout << fib(nth_diagonal) << endl;
  cout << fib(nth_diagonal) % (1000000007) << "\n";
 
 
	return 0; 
}
