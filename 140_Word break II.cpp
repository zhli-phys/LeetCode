class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string>> str;
        int m = wordDict.size();
        int maxlen = 0;
        unordered_set<string> dict;
        for (int i = 0; i < m; i++) {
            dict.insert(wordDict[i]);
            if (wordDict[i].size() > maxlen)
                maxlen = wordDict[i].size();
        }
        return helper(s, 0, str, dict, maxlen);
    }
    
    vector<string> helper(string& s, int i, unordered_map<int, vector<string>>& str, unordered_set<string>& dict, int maxlen) {
        unordered_map<int, vector<string>>::iterator it1 = str.find(i);
        if (it1 != str.end())
            return it1->second;
        int n = s.size();
        vector<string> ans;
        if (i >= n)
            return ans;
        if (maxlen < n - i)
            maxlen = n - i;
        for (int j = 1; j <= maxlen; j++) {
            string head = s.substr(i, j);
            unordered_set<string>::iterator it = dict.find(head);
            if (it != dict.end()) {
                if (i+j == n) {
                    ans.push_back(head);
                }
                else {
                    vector<string> sub = helper(s, i+j, str, dict, maxlen);
                    int m = sub.size();
                    for (int k = 0; k < m; k++) {
                        ans.push_back(head + " " + sub[k]);
                    }
                }
            }
        }
        str[i] = ans;
        return ans;
    }
};