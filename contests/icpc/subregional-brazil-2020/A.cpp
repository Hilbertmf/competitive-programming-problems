#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	double albumCapacity, minNoStickers, maxNoStickers;
 
	cin >> albumCapacity >> minNoStickers >> maxNoStickers;
 
	double ans = albumCapacity/ ((minNoStickers+maxNoStickers)/2);

	// uniform_int_distribution<int> distribution(minNoStickers, maxNoStickers);

	cout << ans << endl;
 
	return 0; 
}
