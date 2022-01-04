class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        int len = words[0].size();
        int m = words.size();
        int n = s.size();
        for (auto& word : words) 
            ++mp[word];
        if (n < m * len)
            return {};
        vector<int> ans;        
        for (int i = 0; i < len; ++i) {
            unordered_map<string, int> curr;
            int count = 0;
            int left = i;
            for (int right = left; right <= n - len; right += len) {
                string str = s.substr(right, len);
                if (mp.find(str) != mp.end()) {
                    ++curr[str];
                    ++count;
                    while (curr[str] > mp[str]) {
                        --curr[s.substr(left, len)];
                        --count;
                        left += len;
                    }
                    if (count == m)
                        ans.push_back(left);
                }
                else {
                    left = right + len;
                    curr.clear();
                    count = 0;
                }
            }
        }
        return ans;
    }
};



















class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> count(26);
        unordered_map<string, int> mp;
        int length = 0;
        int maxSize = 0;
        int n = words.size();
        for (auto& word : words) {
            length += word.size();
            maxSize = max(maxSize, static_cast<int>(word.size()));
            ++mp[word];
            for (char ch : word)
                ++count[ch-'a'];
        }
        int m = s.size();
        if (m < length)
            return {};
        vector<int> curr(26);        
        for (int i = 0; i < length; ++i)
            ++curr[s[i]-'a'];
        vector<int> ans;        
        for (int i = 0; i <= m - length; ++i) {
            bool countMatch = true;
            for (int j = 0; j < 26; ++j) {
                if (curr[j] != count[j]) {
                    countMatch = false;
                    break;
                }
            }
            if (countMatch && match(i, mp, s, maxSize, 0, n)) {
                ans.push_back(i);
            }                    
            --curr[s[i]-'a'];
            if (i + length < m)
                ++curr[s[i+length]-'a'];
        }
        return ans;
    }
    
    bool match(int i, unordered_map<string, int>& mp, const string& s, int maxSize, int c, int n) {
        if (c == n)
            return true;
        bool ans = false;
        for (int j = 1; j <= maxSize; ++j) {
            string str = s.substr(i, j);
            if (mp.find(str) != mp.end() && mp[str] > 0) {
                --mp[str];
                ++c;
                if (match(i + j, mp, s, maxSize, c, n)) 
                    ans = true;
                --c;
                ++mp[str];
            }
            if (ans)
                return true;
        }
        return false;
    }
};