class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dict(26);
        for (int i = 0; i < 26; i++) 
            dict[order[i]-'a'] = i;
        string prev = words[0];
        int n = words.size();
        for (int i = 1; i < n; i++) {
            int len1 = prev.size();
            int len2 = words[i].size();
            int len = min(len1, len2);
            bool identical = true;
            for (int j = 0; j < len; j++) {
                if (dict[prev[j]-'a'] < dict[words[i][j]-'a']) {
                    identical = false;
                    break;
                }
                else if (dict[prev[j]-'a'] > dict[words[i][j]-'a'])
                    return false;
            }
            if (identical && len1 > len2)
                return false;
            prev = words[i];
        }
        return true;
    }
};