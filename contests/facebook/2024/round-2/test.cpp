#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MOD = 998244353;

// Function to check if a substring is a valid number between 1 and 26.
bool isValid(const std::string& s, int start, int len) {
    if (len == 1) {
        return s[start] >= '1' && s[start] <= '9';  // Single digit between 1 and 9
    }
    if (s[start] == '1' || (s[start] == '2' && s[start+1] <= '6')) {
        return true;  // Two-digit number between 10 and 26
    }
    return false;
}

// Function to calculate the number of decodings using dynamic programming.
int countDecodings(const std::string& s) {
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;  // Base case: one way to decode an empty string.

    for (int i = 1; i <= n; ++i) {
        // Single digit valid check
        if (isValid(s, i-1, 1)) {
            dp[i] = (dp[i] + dp[i-1]) % MOD;
        }
        // Two digits valid check
        if (i >= 2 && isValid(s, i-2, 2)) {
            dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
    }
    return dp[n];
}

// Backtracking/DFS to generate all possible uncorrupted strings.
void generateUncorruptedStrings(const std::string& s, int idx, std::string current, std::vector<std::string>& results) {
    if (idx == s.size()) {
        results.push_back(current);
        return;
    }

    if (s[idx] == '?') {
        // Try all digits (1-9 for non-zero position, 0-9 for others).
        for (char c = (idx == 0 ? '1' : '0'); c <= '9'; ++c) {
            current[idx] = c;
            generateUncorruptedStrings(s, idx + 1, current, results);
        }
    } else {
        current[idx] = s[idx];
        generateUncorruptedStrings(s, idx + 1, current, results);
    }
}

int main() {
    int t;  // Number of test cases
    std::cin >> t;

    while (t--) {
        std::string encoded;
        int K;
        std::cin >> encoded >> K;

        // Step 1: Generate all possible uncorrupted strings.
        std::vector<std::string> possibleStrings;
        generateUncorruptedStrings(encoded, 0, std::string(encoded.size(), '0'), possibleStrings);

        // Step 2: For each uncorrupted string, count decodings.
        std::vector<std::pair<std::string, int>> decodedStrings;
        int maxDecodings = 0;

        for (const auto& uncorrupted : possibleStrings) {
            int decodings = countDecodings(uncorrupted);
            decodedStrings.push_back({uncorrupted, decodings});
            maxDecodings = std::max(maxDecodings, decodings);
        }

        // Step 3: Filter out the strings with the maximum number of decodings.
        std::vector<std::string> maxDecodedStrings;
        for (const auto& p : decodedStrings) {
            if (p.second == maxDecodings) {
                maxDecodedStrings.push_back(p.first);
            }
        }

        // Step 4: Sort the strings lexicographically.
        std::sort(maxDecodedStrings.begin(), maxDecodedStrings.end());

        // Output the K-th largest lexicographically string and the number of decodings modulo MOD.
        std::string result = maxDecodedStrings[K-1];
        std::cout << result << std::endl;
        std::cout << maxDecodings % MOD << std::endl;
    }

    return 0;
}
