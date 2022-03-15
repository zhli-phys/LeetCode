class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        vector<int> pos;
        int removed = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ans.push_back('(');
                pos.push_back(i - removed);
            }
            else if (s[i] == ')') {
                if (!pos.empty()) {
                    ans.push_back(')');
                    pos.pop_back();
                }
                else
                    ++removed;
            }
            else
                ans.push_back(s[i]);
        }
        int m = pos.size();
        int idx = 0;
        string sol;
        for (int i = 0; i < ans.size(); ++i) {
            if (idx < m && i == pos[idx])
                ++idx;
            else
                sol.push_back(ans[i]);
        }
        return sol;
    }
};