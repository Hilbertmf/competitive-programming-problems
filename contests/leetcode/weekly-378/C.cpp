class Solution {
public:
    
    int maximumLength(string s) {

        int ans = -1;

        vector<map<int, int>> occ(26);

        for(int j = 0; j < s.size(); ++j) {
            
            int cnt = 0;
            int start = j;
            while (j < s.size() && s[j] == s[start]) {
                cnt++;
                j++;
            }

            if(j < s.size())
                j--;
            
            if(cnt > 2)
                occ[s[start] - 'a'][cnt - 2] += 3;
            if(cnt > 1)
                occ[s[start] - 'a'][cnt - 1] += 2;
            occ[s[start] - 'a'][cnt]++;
        }

        for(auto &mp : occ) {
            for(auto &[k, v] : mp) {
                if(v >= 3 && k > 0)
                    ans = max(ans, k);
            }
        }
        
        return ans;
    }
};