class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        int m = haystack.size();
        int n = needle.size();
        for (int i = 0; i < m - n + 1; i++) {
            bool found = true;
            for (int j = 0; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found)
                return i;
        }
        return -1;
    }
};