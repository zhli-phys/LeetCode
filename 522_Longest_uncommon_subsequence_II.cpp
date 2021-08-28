class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            bool sub = false;
            for (int j = 0; j < n; ++j) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    sub = true;
                    break;
                }
            }
            if (!sub)
                ans = max(ans, static_cast<int>(strs[i].size()));
        }
        return ans;
    }
    
    bool isSubsequence(string& s1, string& s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2)
            return false;
        int j = 0;
        for (int i = 0; i < n1; ++i) {
            while (j < n2 && s1[i] != s2[j])
                ++j;
            if (j >= n2)
                return false;
            ++j;
        }
        return true;
    }
};