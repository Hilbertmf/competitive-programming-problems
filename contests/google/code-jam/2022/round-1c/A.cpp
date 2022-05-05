// WA
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
	int t;
	std::cin >> t;
	for(int test = 0; test < t; test++) {
		int numTowers;
		std::cin >> numTowers;
		
		// vector<int> towers(numTowers);
		unordered_multimap<char, pair<string, int>> towersMap;
		towersMap.reserve(numTowers);
		vector<pair<string, bool>> words;
		for(int i = 0; i < numTowers; ++i) {
			string s;
			std::cin >> s;
			char c = s[0];
			towersMap.insert(make_pair(c, make_pair(s, i+1)));
			words.push_back(make_pair(s, true));
		}

		sort(words.begin(), words.end());
		for(int i = 0; i < words.size(); ++i) {
			// DEBUG(words[i].first);
		}
		
		for(int i = words.size() - 1; i >= 0; --i) {
			int count = 1;
			while(count && words[i].second) {
				string s = words[i].first;
				// DEBUG(s);
				char last = s[s.size()-1];
				count = 0;
				for(int j = words.size() - 1; j >= 0; --j) {
					if(i != j && words[j].first[0] == last && words[j].second) {
						s += words[j].first;
						words[j].second = false;
						count++;
					}
				}
				words[i].first = s;
				// DEBUG(s);
			}
			
		}
		for(int i = 0; i < words.size(); ++i) {
			// DEBUG(words[i].first);
		}
		string res;
		unordered_set<char> chars;
		for(int i = 0; i < words.size(); ++i) {
			if(words[i].second) res += words[i].first;
		}

		bool isPossible = true;
		// DEBUG(res);
		for(int i = 0; i < res.size(); ++i) {
			if(i == res.size() - 1 || res[i] != res[i+1]) {
				if(chars.find(res[i]) != chars.end()) {
					isPossible = false;
					break;
				}
				chars.insert(res[i]);
			}
		}
		if(isPossible && res.size() > 0) cout << "Case #" << test+1 << ": "  << res << endl;
		else cout << "Case #" << test+1 << ": "  << "IMPOSIBLE" << endl;

		// for(auto it = towersMap.begin(); it != towersMap.end(); ++it) {
		// 	string s = (it->second).first;
		// 	int curr = (it->second).second;
		// 	while(true) {
		// 		DEBUG(s);
		// 		DEBUG((it->second).second);
		// 		if(curr = !- 1) break;
		// 		if( (s[s.size()-1] == s[0] && towersMap.count(s[s.size()-1]) > 1) || 
		// 			(s[s.size()-1] != s[0] && towersMap.count(s[s.size()-1]) > 0)) {
					
		// 			int count = 0;
		// 			auto range = towersMap.equal_range(s[s.size()-1]);
		// 			auto itr = range.first;
		// 			for(itr; itr != range.second ; ++itr) {
		// 				if(curr != (itr->second).second && (itr->second).second != -1) {
		// 					s+= (itr->second).first;
		// 					(itr->second).second = -1;
		// 					// towersMap[itr->first] = make_pair((itr->second).first, 0);
		// 				}
		// 				else if((itr->second).second == -1) {
		// 					count++;
		// 				}
		// 			}
		// 			int tmp = towersMap.count(s[s.size()-1]);
		// 			DEBUG(s);
		// 			it->second = make_pair(s, (it->second).second);
		// 			if(count >= towersMap.count(s[s.size()-1])) {
		// 				DEBUG(s[s.size()-1]);
		// 				break;
		// 			}
		// 		}

		// 		else break;
		// 	}
		// }

		// string res;
		// unordered_set<char> chars;
		// for(auto it = towersMap.begin(); it != towersMap.end(); ++it) {
		// 		string s = (it->second).first;
		// 	if((it->second).second != -1) {
		// 		res += s; 
		// 	}
		// 	// cout << "string:" << s << " n:" << (it->second).second << endl;
		// }
		// bool isPossible = true;
		// for(int i = 0; i < res.size(); ++i) {
		// 	if(i == res.size() - 1 || res[i] != res[i+1]) {
		// 		if(chars.find(res[i]) != chars.end()) {
		// 			isPossible = false;
		// 			break;
		// 		}
		// 		chars.insert(res[i]);
		// 	}
		// }
		// if(isPossible) cout << "Case #" << test+1 << ": "  << res << endl;
		// else cout << "Case #" << test+1 << ": "  << "IMPOSIBLE\n" << endl;
		// printf("Case #%d: %.6f\n", test+1, ans);
	}
	return 0; 
}
