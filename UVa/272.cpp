#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
 
using namespace std;
 
int main() 
{ 
	char str[65500];
  char str_aux[65500];
  int i, aux, j;

  while(cin.getline(str, sizeof str) && !cin.eof())
  {
    for (i = 0, j=0; i < strlen(str); i++, j++)
    {
      if (str[i] == '"')
      {
        if (aux % 2 == 0)
        {
          str_aux[j] = '`';
          str_aux[j+1] = '`';
        } else {
          str_aux[j] = '\'';
          str_aux[j+1] = '\'';
        }
        aux++;
        j++;
      } else {
        str_aux[j] = str[i];
      }    
    }
    cout << str_aux << endl;
  }
  // printf("%s\n", str);
  
  // cout << str;
  
 
	return 0; 
}
