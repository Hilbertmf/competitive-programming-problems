#include <bits/stdc++.h> 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
 
using namespace std;
 
int main() 
{ 
	char num[20] = {'0'};
  char aux_num[20] = {'0'};
	cin >> num;
  bool res = true;
  int length = strlen(num);
  for (int i = length - 1, j=0; i >= 0; i--, j++)
  {
    if(num[j] == '2' || num[j] == '3' || num[j] == '4' || num[j] == '5' || num[j] == '7')
    {
      res = false;
      break;
    }
    else if(num[j] == '6')
      aux_num[i] = '9';
    else if(num[j] == '9')
      aux_num[i] = '6';
    else
      aux_num[i] = num[j];
  }
  
  if (res)
  {
    // strcmp returns 0 if the strings have the same content
    if(strcmp(num, aux_num) == 0)
      printf("Sim\n");
    else
      printf("Nao\n");      
  } else {
    printf("Nao\n");
  }
	return 0; 
}
