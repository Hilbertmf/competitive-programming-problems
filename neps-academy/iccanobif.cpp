#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int n;
 
	scanf("%d", &n);
	unsigned long long int fib[n+10] = {0};
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < n; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	
	for (int i = n-1; i >= 0; i--)
	{
		printf("%llu ", fib[i]);
	}
	printf("\n");
 
	return 0; 
}
