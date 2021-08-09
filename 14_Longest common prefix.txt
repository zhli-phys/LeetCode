class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = strs.size();
        if (strs.empty())
            return "";
        int n = strs[0].size();
        int len = 0;
        while (len < n) {
            char ch = strs[0][len];
            bool common = true;
            for (int i = 1; i < m; i++) {
                if (strs[i][len] != ch) {
                    common = false;
                    break;
                }
            }
            if (common)
                len++;
            else
                break;
        }
        return string(strs[0].begin(), strs[0].begin() + len);
    }
};