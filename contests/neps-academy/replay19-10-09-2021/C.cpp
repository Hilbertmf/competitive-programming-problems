// https://neps.academy/br/competition/1019/exercise/1780
#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int aLength, bLength;
	int a[510];
	int b[510];
	int c[1010];

	scanf("%d %d", &aLength, &bLength);

	for(int i=0; i<aLength;i++) {
		cin >> a[i];
	}

	
	for(int i=0; i<bLength;i++) {
		cin >> b[i];
	}
//  	      |
// A = 2
// B = 1 2

// input:

// |
// iA = 3
// iB = 7
// c = [1,3,3,3,4,5,6,7,8,8,9]
// 3 8
//       |
// 1 3 8
//                 |
// 3 3 4 5 6 7 8 9


	int idxA = 0, idxB = 0, i = 0;
	for(i=0; idxA < aLength && idxB < bLength;i++) {
		// if (idxA > noInts)

		if(a[idxA] <= b[idxB]) {
			printf("%d\n", a[idxA]);
			c[i] = a[idxA];
			idxA++;
		} else{
			// printf("b\n");
			printf("%d\n", b[idxB]);
			c[i] = b[idxB];
			idxB++;
		}
	}
	while(idxA < aLength) {
		printf("%d\n", a[idxA]);
		c[i] = a[idxA++];
		
	}

	while(idxB < bLength) {
		printf("%d\n", b[idxB]);
		c[i] = b[idxB++];
	}

	// for(int i=0; i < aLength + bLength ;i++) 
	// 	cout << c[i] << endl;
	return 0; 
}
