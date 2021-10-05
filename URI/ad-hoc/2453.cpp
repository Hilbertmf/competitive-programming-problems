// OBI problem: https://olimpiada.ic.unicamp.br/pratique/p2/2014/f1/lingua/
// URI version: https://www.urionlinejudge.com.br/judge/pt/problems/view/2453
#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;

int main() 
{ 
	string msg;
	getline(cin, msg);
	int length = msg.length();
	string aux(length, ' ');
	
	int count = 0, j = 0;
	for (int i = 0; i < length; i++)
	{
		if(msg[i] != ' ')
		{
			if (count % 2 != 0)
			{
				aux[j] = msg[i];
				j++;
			}
			count++;
		} 
		else
		{
			j++;
		}
	}

	string result = aux.substr(0, j);
	cout << result << "\n";
	// printf("j = %d\n",j);
 
	return 0; 
}
