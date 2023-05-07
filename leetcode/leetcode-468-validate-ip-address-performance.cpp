#include <bits/stdc++.h>
using namespace std;

// performance focused solution
// runs under 1ms
class Solution {
public:
    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while(getline(ss, word, delim))
            if(word.size() > 0) 
				words.push_back(word);

        return words;
    }
    
    string validIPAddress(string queryIP) {
        bool neither = false, ipv4 = false, ipv6 = false;
        int count_dot = 0, count_colon = 0;
        for(auto c : queryIP) {
            if(c == '.') count_dot++;
            if(c == ':') count_colon++;
        }
        // ipv4
        if(count_dot == 3 && count_colon == 0) {
            vector<string> words = split(queryIP, '.');
            if(words.size() == 4) {

                for(auto& word : words) {
                    if(word.size() > 3 ||
                    (word[0] == '0' && word.size() > 1)) { // leading 0s
                        neither = true;
                        break;
                    }
                    for(char c : word) {
                        if(!(c >= '0' && c <= '9')) {
                            neither = true;
                            break;
                        }
                    }
                    if(!neither) {
                        int address = stoi(word);
                        if(address < 0 || address > 255) neither = true;
                    }
                    if(neither) break;
                }
                ipv4 = !neither;
            }
        }
        // ipv6
        else if(count_dot == 0 && count_colon == 7) {
            vector<string> words = split(queryIP, ':');
            
            if(words.size() == 8) {
                for(auto& word : words) {
                    if(word.size() == 0 || word.size() > 4) neither = true;
                    
                    for(auto c : word) {
                        if(!((c >= '0' && c <= '9') ||
                        (c >= 'a' && c <= 'f') ||
                        (c >= 'A' && c <= 'F'))) {
                            neither = true;
                            break;
                        }
                    }
                    if(neither) break;
                }
                ipv6 = !neither;
            }
        }
        else {
            neither = true;
        }

        if(ipv4) return "IPv4";
        else if(ipv6) return "IPv6";
        else return "Neither";
    }
};