#include <iostream> 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{ 
	string binaryNo;
 
	cin >> binaryNo;
	int decimalNo = stoi(binaryNo, 0, 2);

	int m;
	cin >> m;
	int numbers[m+10];
	for (int i = 0; i < m; i++)
	{
		cin >> numbers[i];
	}

	vector<int> divisibleNo;
	for (int i = 0; i < m; i++)
	{
		if(decimalNo % numbers[i] == 0) {
			divisibleNo.push_back(numbers[i]);
		}
	}

	sort(divisibleNo.begin(), divisibleNo.end());
	if (divisibleNo.size() > 0)
	{
		for (auto i = divisibleNo.begin(); i != divisibleNo.end(); i++)
		{
			cout << *i << " ";
		}
	}
	else
	{
		cout << "Nenhum";
	}
	cout << endl;
	return 0; 
}
