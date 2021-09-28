#include <bits/stdc++.h> 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;
int num;
bool isPrime()
{
  if (num <= 1)
    return false;
  
  for (int i = 2; i < sqrt(num); i++)
  {
    if(num % i == 0)
      return false;
  }
  return true;
}

int main() 
{ 
	
	scanf("%d", &num);
  
	if (isPrime())
  {
    printf("Tio\n");
  } else {
    printf("Normal\n");
  }
  
 
	return 0; 
}
