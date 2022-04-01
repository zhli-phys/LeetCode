class Solution {
public:
    vector<string> expand(string s) {
        vector<string> chars;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '{') {
                ++i;
                string choices;
                while (s[i] != '}') {
                    if (s[i] != ',')
                        choices.push_back(s[i]);
                    ++i;
                }
                sort(choices.begin(), choices.end());
                chars.push_back(choices);
            }
            else
                chars.push_back(string(1, s[i]));
        }
        
        vector<string> ans;
        string curr;
        dfs(0, curr, ans, chars);
        return ans;
    }
    
    void dfs(int i, string& curr, vector<string>& ans, vector<string>& chars) {
        if (i == chars.size())
            ans.push_back(curr);
        else {
            for (char ch : chars[i]) {
                curr += ch;
                dfs(i+1, curr, ans, chars);
                curr.pop_back();
            }
        }
    }
};