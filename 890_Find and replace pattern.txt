class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.size();
        vector<int> last_appearance(n, -1);
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (pattern[j] == pattern[i]) {
                    last_appearance[i] = j;
                    break;
                }
            }
        }
        vector<string> ans;
        for (auto&& word : words) {
            bool flag = true;
            for (int i = 1; i < n; ++i) {
                if (last_appearance[i] >= 0) {
                    if (word[last_appearance[i]] != word[i]) {
                        flag = false;
                        break;
                    }
                }
                else {
                    for (int j = i - 1; j >= 0; --j) {
                        if (word[j] == word[i]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag)
                        break;
                }
            }
            if (flag)
                ans.push_back(word);
        }
        return ans;
    }
};















//use hash map 
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto&& word : words) {
            unordered_map<char, char> mp;
            size_t n = pattern.size();
            bool flag = true;
            for (size_t i = 0; i < n; ++i) {
                if (mp.find(word[i]) == mp.end() || mp[word[i]] == pattern[i]) 
                    mp[word[i]] = pattern[i];
                else {
                    flag = false;
                    break;
                }
            }
            vector<bool> seen(26, false);
            if (flag) {
                for (auto it = mp.begin(); it != mp.end(); ++it) {
                    if (seen[it->second - 'a']) {
                        flag = false;
                        break;
                    }
                    seen[it->second - 'a'] = true;
                }
            }
            if (flag)
                ans.push_back(word);
        }
        return ans;
    }
};