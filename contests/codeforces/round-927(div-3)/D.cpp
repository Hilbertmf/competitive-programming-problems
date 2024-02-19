#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

char trump;

struct Card {
    char suit;
    int rank;
};

int main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        cin >> trump;

        unordered_map<char, vector<int>> normal_cards;
        vector<int> trump_cards;
        for(int i = 0; i < 2*n; ++i) {
            char suit;
            int rank;
            cin >> rank >> suit;
            if(suit == trump) {
                trump_cards.push_back(rank);
            }
            else {
                normal_cards[suit].push_back(rank);
            }
        }

        int carry = 0;
        for(auto &[suit, cards] : normal_cards) {
            if (cards.size() % 2 != 0) {
                carry++;
            }
        }

        bool possible = trump_cards.size() >= carry &&
                      ((trump_cards.size() - carry) % 2 == 0);

        if(possible) {
            
            vector<Card> remainder;
            for(auto &[suit, cards] : normal_cards) {
                sort(cards.begin(), cards.end());

                for(int i = 0; i < cards.size() - 1; i += 2) {
                    cout << cards[i] << suit << " " <<
                    cards[i + 1] << suit << "\n";
                }
                
                if (cards.size() % 2 != 0) {
                    remainder.push_back((Card){suit, cards.back()});
                }
            }

            sort(trump_cards.begin(), trump_cards.end());
            int idx = 0;
            for(int i = 0; i < remainder.size(); ++i, ++idx) {
                cout << remainder[i].rank << remainder[i].suit << " " <<
                trump_cards[idx] << trump << "\n";
            }

            for(; idx < trump_cards.size(); idx += 2) {
                cout << trump_cards[idx] << trump << " " <<
                trump_cards[idx + 1] << trump << "\n";
                
            }
        }
        else {
            cout << "IMPOSSIBLE" << "\n";
        }

    }
    
    return 0;
}
