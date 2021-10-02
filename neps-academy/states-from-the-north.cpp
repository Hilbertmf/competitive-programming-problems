#include <bits/stdc++.h>
using namespace std;

int main() {
	string state;
	cin >> state;
	if (state.compare("acre") == 0 || state.compare("amapa") == 0 || 
			state.compare("amazonas") == 0 || state.compare("para") == 0 ||
			state.compare("rondonia") == 0 || state.compare("roraima") == 0 ||
			state.compare("tocantins") == 0)
		cout << "Regiao Norte" << endl;
	else
		cout << "Outra regiao" << endl;
	return 0;
}