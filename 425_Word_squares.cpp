class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        unordered_map<string, unordered_set<string>> prefix;
        for (auto& word : words) {
            int m = word.size();
            for (int i = 1; i <= m; ++i) 
                prefix[word.substr(0, i)].insert(word);
        }
        vector<vector<string>> ans;
        for (auto& word : words) {
            int m = word.size();
            bool flag = true;
            vector<vector<string>> strs[m];
            strs[0] = {{word}};
            for (int i = 1; i < m; ++i) {
                for (auto& str : strs[i-1]) {
                    string target;
                    for (int j = 0; j < i; ++j)
                        target += str[j][i];
                    if (prefix.find(target) != prefix.end()) {
                        for (auto& s : prefix[target]) {
                            auto new_str = str;
                            new_str.push_back(s);
                            strs[i].push_back(new_str);
                        }
                    }
                }                
            }
            ans.insert(ans.end(), strs[m-1].begin(), strs[m-1].end());
        }
        return ans;
    }
};