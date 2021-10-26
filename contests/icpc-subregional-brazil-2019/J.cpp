#include <bits/stdc++.h> 
using namespace std; 
#define INF (int)1e9 
#define LONGINF (long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
void initArray(int arr[], int length, int val) { 
	for (int i = 0; i < length; i++) 
		arr[i] = val; 
	return; 
} 

int getLessFrequent(vector<int>& currPlayerHand) { 
	int lessFrequent = INF;
	int noOfTimes = INF;
	int table[14] = {0};
	for (auto it = currPlayerHand.begin(); it != currPlayerHand.end(); it++) {
		table[*it]++;
	}

	for (int i = 13; i > 0; i--) {
		if(table[i] > 0) {
			noOfTimes = min(noOfTimes, table[i]);
			if(noOfTimes == table[i]) {
				lessFrequent = i;
			}
		}
	}
	return lessFrequent;
}

bool hasJoker(vector<int>& currPlayerHand) {
	int jokerCard = 0;
	for (auto it = currPlayerHand.begin(); it != currPlayerHand.end(); it++)
		if(*it == jokerCard) // we're using joker as 0
			return true;
	
	return false;
}

bool hasWinner(vector<vector<int>>& cards, int& winner) {
	
	for (int player = 0; player < cards.size(); player++)
	{
		if(cards[player].size() != 4)
			continue;
		int card = cards[player][0];
		bool allEqual = true;
		for (auto it = cards[player].begin(); it != cards[player].end(); it++)
		{
			if(card != *it)
				allEqual = false;
		}
		if(allEqual) {
			winner = min(winner, player+1);
		}
	}
	if(winner != INF)
		return true;
	return false;
}
 
int main() { 
	fastio; 
	// ifstream cin("in.txt"); 
	// ofstream cout("out.txt"); // cout to file 
	//freopen("out.txt","w",stdout); // use this one for printf to file 

	int noPlayers, startPlayer;
	int winner = INF;
	cin >> noPlayers >> startPlayer;
	vector<vector<int>> cards(noPlayers, vector<int> (4, 0));

	for(int i = 0; i < noPlayers; i++)  {
		string cardString;
		cin >> cardString;
		for (int j = 0; j < 4; j++)
		{
			if(cardString[j] == 'A')
				cards[i][j] = 1;
			else if(cardString[j] == 'D')
				cards[i][j] = 10;
			else if(cardString[j] == 'Q')
				cards[i][j] = 11;
			else if(cardString[j] == 'J')
				cards[i][j] = 12;
			else if(cardString[j] == 'K')
				cards[i][j] = 13;
			else
				cards[i][j] = cardString[j] - '0';
		}
	}
	
	int currPlayer = startPlayer - 1;
	int nextPlayer = currPlayer + 1;
	if(nextPlayer > noPlayers - 1)
		nextPlayer = 0;
	
	// setup start of the game:
	// let's use as convention: joker = 0
	int jokerCard = 0;
	cards[currPlayer].push_back(jokerCard); // add joker
	bool canPassJoker = false;
	int turnsJokerIsStill = 0;

	// run game
	for (currPlayer, nextPlayer, turnsJokerIsStill;
			 !hasWinner(cards, winner);
			 currPlayer++, nextPlayer++)
	{
		if(nextPlayer > noPlayers - 1)
			nextPlayer = 0;
		if(currPlayer > noPlayers - 1) // go around
			currPlayer = 0;
		
		if(turnsJokerIsStill == 0)
			canPassJoker = false;
		else
			canPassJoker = true;
			
		// starting round
		if(hasJoker(cards[currPlayer]) && canPassJoker) {
			
			// add joker to next
			cards[nextPlayer].push_back(jokerCard);
			turnsJokerIsStill = 0;
			// remove joker
			auto pos = find(cards[currPlayer].begin(), cards[currPlayer].end(), jokerCard);
			cards[currPlayer].erase(pos);
		}
		else {
			int lessFrequent = getLessFrequent(cards[currPlayer]);
			cards[nextPlayer].push_back(lessFrequent);
			// remove card from currPlayer's hand
			auto pos = find(cards[currPlayer].begin(), cards[currPlayer].end(), lessFrequent);
			cards[currPlayer].erase(pos);
			
			turnsJokerIsStill++;
		}
	}
	
	cout << winner << endl;
	return 0; 
}
