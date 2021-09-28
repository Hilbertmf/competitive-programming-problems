#include <bits/stdc++.h> 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;
 
int main() 
{ 
	unsigned long long int n;
  unsigned long long int height;
 
	cin >> n;
 
	height = (floor(sqrt(1+8*n)) - 1)/2;
  cout << (unsigned long long int)floor(height) << "\n";
 
	return 0; 
}
