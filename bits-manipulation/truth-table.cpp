#include <iostream>
using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl 

int main() {
	
	
	int a[] = {1, 1, 0, 0};
	int b[] = {1, 0, 1, 0};

  bool ua[] = {true, true, false, false};
	bool ub[] = {true, false, true, false};
	
	printf("Truth table:\n");
	printf("| a | b |AND| OR|XOR|NOR|\n");
	for(int i=0;i<4;i++) {
		printf("| %d | %d | %d | %d | %d | %d |\n", a[i], b[i], a[i]&b[i],
		a[i]|b[i], a[i]^b[i], !(a[i]|b[i]));
		
	}

  // swapping values without auxiliar variable: only works for integers
  int n1, n2;
  n1 = -10;
  n2 = -30;
  printf("n1 = %d | n2 = %d\n", n1, n2);
  n1 = n1^n2;
  n2 = n1^n2;
  n1 = n1^n2;
  printf("n1 = %d | n2 = %d\n", n1, n2);
  
  n1 = 2;
  n2 = 3;
  printf("n1 = %d | n2 = %d\n", n1, n2);
  // swapping values w/ arithmetics
  n1 = n1 + n2;
  n2 = n1 - n2;
  n1 = n1 - n2;
  printf("n1 = %d | n2 = %d\n", n1, n2);
  
  unsigned int u1 = 1, u2 = 2, _or, nor;
  DEBUG(~u1);
  DEBUG(~u2);
  // nor: ~ (or)
  _or = u1|u2;
  DEBUG(_or);
  nor = ~_or;
  DEBUG(nor);
  
  // creating masks
  // mask for the ith bit: left shift i bits from 1: 1 << i
  int mask = 1 << 5;
  DEBUG(mask);
  // to get ith bit:
  // (value & mask) != 0
  // to set ith bit:
  // value = value | mask
  // clear the ith bit:
  // invert mask: ~mask, then and:
  // value = value & (~mask)
	return 0;
}