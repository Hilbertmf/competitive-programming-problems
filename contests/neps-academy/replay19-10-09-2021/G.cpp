// https://neps.academy/br/competition/1019/exercise/1785
#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
bool isInRange(int l,int r,int x) {
	if(x >= l && x <= r) // l <= x <= r
		return true;
	return false;
}

int main() 
{ 
	int x, l, r, ans;
 
	scanf("%d %d %d", &x, &l, &r);
 
	if(l == r)
		printf("%d\n",l);
	else if(isInRange(l,r,x))
		printf("%d\n", x);
	else {
		if(x < l)
			printf("%d\n", l);
		else
			printf("%d\n", r);
	}
 
	return 0; 
}
