#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& s, char separator) {
    vector<string> res;
    string aux;
    stringstream ss(s);
    while (getline(ss, aux, separator)) {
        if(!aux.empty())
            res.push_back(aux);
    }
    return res;
}

int getHash(string& s) {
    int res = 0;

    for(char c : s) {
        res += c;
        res *= 17;
        res %= 256;
    }

    return res;
}

list<pair<string, int>>::iterator findInList(list<pair<string, int>>& list, string& str) {
    auto it = list.begin();
    for(it; it != list.end(); ++it) {
        if(it->first == str) break;
    }
    return it;
}

int main() {

    string line;
    cin >> line;
    vector<string> steps = split(line, ',');
    vector<list<pair<string, int>>> hashmap(256);
    int hash;

    for(auto &s : steps) {
        if(s.find('-') != string::npos) {

            string elem = s.substr(0, s.find('-'));
            hash = getHash(elem);
            if(!hashmap[hash].empty()) {

                auto it = findInList(hashmap[hash], elem);
                if(it != hashmap[hash].end() && it->first == elem)
                    hashmap[hash].erase(it);
            }
        }
        else {
            
            string elem = s.substr(0, s.find('='));
            hash = getHash(elem);
            string lens_str = s.substr(s.find('=') + 1);
            int lens = stoi(lens_str);
            auto it = findInList(hashmap[hash], elem);
            if(it != hashmap[hash].end() && it->first == elem)
                it->second = lens;
            else
                hashmap[hash].push_back({elem, lens});
        }

    }

    int ans = 0;
    for(int i = 0; i < 256; ++i) {
        if(!hashmap[i].empty()) {
            int slot = 1;
            for(auto &[elem, lens] : hashmap[i]) {
                ans += (i + 1) * slot * lens;
                slot++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}