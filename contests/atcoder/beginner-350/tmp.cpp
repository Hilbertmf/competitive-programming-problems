#include <bits/stdc++.h>
using namespace std;

int main() {

    int occ = 0, num_words = 0;
    char letter;
    string word;
    cin >> letter;

    while (getline(cin, word, ' ')) {
        if (!word.empty() && word != " ")
            num_words++;  
        if (word.find(letter) != string::npos)
            occ++;
    }
    
    cout << fixed << setprecision(1) << double(occ * 100) / num_words << "\n";

    return 0;
}