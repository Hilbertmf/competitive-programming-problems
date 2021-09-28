#include <bits/stdc++.h> 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;

bool areIsomorphic(string str1, string str2)
{
  int m = str1.length();
  int n = str2.length();
  
  if(n != m)
    return false;

  bool marked[1000010] = {false};

  int map[1000010];
  memset(map, -1, sizeof(map));

  for (int i = 0; i < n; i++)
  {
    // if character is seen for the first time
    if(map[str1[i]] == -1)
    {
      // then current char of str2 must have not appeared before
      if (marked[str2[i]])
        return false;

      // mark currenct char of str2 as visited
      marked[str2[i]] = true;

      // and store mapping or current chars
      map[str1[i]] = str2[i];
    }

    // if not first appeance in str1 then check if previous appearence mapped to
    // same char of str2
    else if(map[str1[i]] != str2[i])
      return false;
  }
  return true;
}

int main() 
{ 
	int aux;
  string str1;
  string str2;
	cin >> str1;
  cin >> str2;
  if (areIsomorphic(str1,str2))
  {
    printf("Sim\n");
  } else {
    printf("Nao\n");
  }
 
	return 0; 
}
