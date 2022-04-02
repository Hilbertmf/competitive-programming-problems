// memory exceeded solution
long long sumScores(string s) {
	vector<string> prefixes(s.size());
	string build;
	long long score = 0;

	for(auto it = s.rbegin(); it != s.rend(); it++) {
		build += *it;
		string aux = build;
		reverse(aux.begin(), aux.end());
		prefixes.push_back(aux);
	}

	for(string &prefix : prefixes) {
		long long count = 0;
		for(int i = 0; i < prefix.size() && prefix[i] == s[i]; i++) {
			count++;
		}
		score += count;
	}

	return score;
}

// time limit exceeded solution
long long sumScores(string s) {
	vector<string> prefixes(s.size());
	string build;
	long long score = 0;

	for(auto it = s.rbegin(); it != s.rend(); it++) {
		build += *it;
		string aux = build;
		reverse(aux.begin(), aux.end());
		prefixes.push_back(aux);
	}
	return score;
}