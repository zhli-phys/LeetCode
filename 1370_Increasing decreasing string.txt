class Solution {
public:
    string sortString(string s) {
        vector<int> counts(26);
        for (char ch : s)
            counts[ch-'a']++;
        int n = s.size();
        int i = 0;
        string ans; 
        while (ans.size() < n) {
            for (int j = 0; j < 26; j++) {
                if (counts[j] > 0) {
                    ans.push_back('a'+j);
                    counts[j]--;
                }
            }
            for (int j = 25; j >= 0; j--) {
                if (counts[j] > 0) {
                    ans.push_back('a'+j);
                    counts[j]--;
                }
            }
        }
        return ans;
    }
};