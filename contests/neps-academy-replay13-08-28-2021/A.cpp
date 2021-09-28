#include <bits/stdc++.h> 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;
 
int main() 
{ 
	int n;
  double height;
 
	scanf("%d", &n);
 
	height = (floor(sqrt(1+8*n)) - 1)/2;
  printf("%d\n", (int)floor(height));
 
	return 0; 
}
