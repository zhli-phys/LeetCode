class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int j = 0;
        for (int i = 0; i < n1; ++i) {
            while (j < n2 && t[j] != s[i])
                ++j;
            if (j >= n2)
                return false;
            ++j;
        }
        return true;
    }
};