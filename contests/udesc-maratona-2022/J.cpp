#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
 
int main() { 
	FASTIO;
	int numCards;
	cin >> numCards;

	vector<pair<char, char>> cards(numCards);
	char v, t;
	int rounds = -1;

	for(int i = 0; i < numCards; ++i) {
		cin >> v >> t;
		cards[i] = {v, t};
	}

	queue<pair<char, char>> hand;

	unordered_map<char, unordered_map<char, int>> cardsInHand;
	int i;
	for(i = 0; i < numCards && i < 9; ++i) {
		hand.push(cards[i]);
		cardsInHand[cards[i].first][cards[i].second]++;
		if(cardsInHand[cards[i].first].size() >= 3) {
			rounds = i + 1;
			break;
		}
	}

	for(i; rounds == -1 && i < cards.size(); ++i) {
		auto card = hand.front();
		hand.pop();
		cardsInHand[card.first][card.second]--;
		if(cardsInHand[card.first][card.second] <= 0)
			cardsInHand[card.first].erase(card.second);

		hand.push(cards[i]);
		cardsInHand[cards[i].first][cards[i].second]++;
		if(cardsInHand[cards[i].first].size() >= 3) {
			rounds = i + 1;
		}
	}

	cout << rounds << "\n";
	return 0; 
}
