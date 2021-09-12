#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	int aux;
	int col_init, col_end, posy, row_init, row_end;
	char col_init_aux, col_end_aux;
	scanf("%c%d %c%d", &col_init_aux, &row_init, &col_end_aux, &row_end);
	col_init = col_init_aux - 'a' + 1;
	col_end = col_end_aux - 'a' + 1;
	bool is_valid = false;
	
	if( (abs(row_init - row_end) == 1) && (abs(col_init - col_end) == 2 ) ||
			(abs(row_init - row_end) == 2) && (abs(col_init - col_end) == 1 ))
		is_valid = true;
 	if(is_valid)
		printf("VALIDO\n");
	else
		printf("INVALIDO\n");
	return 0; 
}
