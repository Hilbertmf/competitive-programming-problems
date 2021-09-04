#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;
 
int main() 
{ 
	int cases, a, b;
  char res;
	scanf("%d", &cases);
  
  while (cases--)
  {
    scanf("%d %d", &a, &b);
    res = a == b ? '=' : a > b ? '>' : '<';
    printf("%c\n", res);
  }
 
	return 0; 
}
