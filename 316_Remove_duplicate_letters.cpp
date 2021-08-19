class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastPos(26, -1);
        int n = s.size();
        for (int i = 0; i < n; ++i)
            lastPos[s[i]-'a'] = i;
        stack<char> sk;
        vector<bool> seen(26, false);
        for (int i = 0; i < n; ++i) {
            if (seen[s[i]-'a'])
                continue;
            while (!sk.empty() && sk.top() > s[i] && lastPos[sk.top()-'a'] > i) {
                seen[sk.top()-'a'] = false;
                sk.pop();
            }
            sk.push(s[i]);
            seen[s[i]-'a'] = true;
        }
        string ans;
        while (!sk.empty()) {
            ans.push_back(sk.top());
            sk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};