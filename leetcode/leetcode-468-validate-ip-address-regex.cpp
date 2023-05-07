#include <bits/stdc++.h> 
using namespace std; 

// solution w/ regex
// runs in approximately 44ms
class Solution {
public:
    vector<string> split(string s, char delim) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while(getline(ss, word, delim)) {
            words.push_back(word);
        }
        return words;
    }
    
    string validIPAddress(string queryIP) {
        if(queryIP.size() > 39) return "Neither";

        bool ipv4 = false, ipv6 = false, neither = false;
        
        regex ipv4Rgx("([0-9]{1,3}\\.){4}");
        regex ipv6Rgx("([0-9a-fA-F]{1,4}:){8}");

        if(regex_match(queryIP + '.', ipv4Rgx)) {
            vector<string> words = split(queryIP, '.');
            for(string& word : words) {
                int address = stoi(word);
                if((word[0] == '0' && word.size() > 1)
                || address < 0 || address > 255) {
                    neither = true;
                    break;
                }
            }
            ipv4 = !neither;
        }
        else if(regex_match(queryIP + ':', ipv6Rgx)) {
            ipv6 = true;
        }

        if(ipv4) return "IPv4";
        else if(ipv6) return "IPv6";
        else return "Neither";
    }
};