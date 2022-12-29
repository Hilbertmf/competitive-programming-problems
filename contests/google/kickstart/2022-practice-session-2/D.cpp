// accepted
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b55464
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

unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

bool checkSpell(string& s) {
    unordered_set<string> words;
    words.reserve(s.size() * s.size());

    for(int i = 0; i < s.size(); ++i) {
        string tmp;
        int numVowels = 0;
        int j = i;
        for(; j < s.size() && numVowels < 2; ++j) {
            tmp += s[j];
            if(vowels.find(s[j]) != vowels.end())
                numVowels++;
        }
        if(numVowels >= 2) 
            words.insert(tmp);

        for(; j < s.size(); ++j) {
            tmp += s[j];
            words.insert(tmp);
        }
    }

    for(auto &word : words) {

        int foundWords = 0;
        int i = 0;

        for(int f = 0; f < 2; ++f) {
            for(; i < s.size(); ++i) {
                string curr = s.substr(i, word.size());
                if(curr == word) {
                    foundWords++;
                    break;
                }
            }
            i += word.size();
            while(i < s.size() && vowels.find(s[i]) == vowels.end()) {
                ++i;
            }
            ++i;
        }

        if(foundWords == 2)
            return true;
    }
    
    return false;
}

int main() { 
    FASTIO;
    int tests;
    cin >> tests;

    for(int t = 0; t < tests; ++t) {
        string s;
        cin >> s;
        bool isSpell = checkSpell(s);

        if(isSpell)
            cout << "Case #" << t+1 << ": Spell!" << "\n";
        else 
            cout << "Case #" << t+1 << ": Nothing." << "\n";			
    }
    
    return 0; 
}
