#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
void initArray(int arr[], int length, int val) { 
	for (int i = 0; i < length; i++) 
		arr[i] = val; 
	return; 
} 
 
void solve() { 
 
} 
 
bool allBulbsTurnedOff(int bulbs[], int numBulbs) { 
	for (int i = 0; i < numBulbs; i++) {
		if(bulbs[i] > 0)
			return false;
	}
	return true;
} 

string getState(int bulbs[], int numBulbs) {
	string res = "";
	for (int i = 0; i < numBulbs; i++) {
		res += '0' + bulbs[i];
	}
	return res;
}
bool hasRepeatedState(int bulbs[], int numBulbs, vector<string> states, string state) {
	for (auto it = states.begin(); it != states.end(); it++) {
		if(*it == state)
			return true;
	}
		
	
	return false;
}

int main() { 
	FASTIO; 
	//ifstream cin("in.txt"); 
	//ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	int numSwitches, numBulbs, turnedOn; 
	cin >> numSwitches >> numBulbs >> turnedOn;
	int bulbsFromSwitch[1010] = {0};
	int turnedOnBulbs[turnedOn+1];
	vector<vector<int>> switchesAndBulbs;
	// int switches[numSwitches+1]; // bulbs associated w/ switch
	
	for(int i = 0; i < turnedOn; i++) { 
		cin >> turnedOnBulbs[i]; 
	}
	
	for(int i = 0; i < numSwitches; i++) { 
		cin >> bulbsFromSwitch[i];
		vector<int> bulbVec;
		for(int j = 0; j < bulbsFromSwitch[i]; j++) { 
			int bulb;
			cin >> bulb;
			bulbVec.push_back(bulb);
		}
		switchesAndBulbs.push_back(bulbVec);
	}

	int bulbs[1010] = {0};
	// populate bulbs states
	for (int i = 0; i < turnedOn; i++) {
		bulbs[turnedOnBulbs[i] - 1] = 1;
	}

	int count = 0;
	vector<string> states;
	string state = getState(bulbs, numBulbs);
	states.push_back(state);
	int limitLoop = 0;
	for(int i = 0; i < numSwitches; i++, count++) { 
		for (int j = 0; j < bulbsFromSwitch[i]; j++)
		{
			int currIdx = switchesAndBulbs[i][j] - 1;
			bulbs[currIdx] = (bulbs[currIdx] > 0) ? 0 : 1;
		}
		if(allBulbsTurnedOff(bulbs, numBulbs)) {
			count++;
			break;
		}
		if(i == numSwitches - 1) {
			i = -1;
			string currState = getState(bulbs, numBulbs);
			states.push_back(currState);
			// if we find a repeating state of switches then it'll repeat forever
			if (hasRepeatedState(bulbs, numBulbs, states, currState)) {
				limitLoop++;
				if(limitLoop >= 2) {
					count = -1;
					break;
				}
			}
		}		
	}

	cout << count << endl; 
	return 0; 
}
