class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "")
            return "";
        string s_rev(s);
        reverse(s_rev.begin(), s_rev.end());
        int len = s.size();
        int maxlen = 0;
        int start = 0;
        for (int i = 0; i < len; ) {
            for (int j = 1; j <= len; j++) {
                if (i + j >= len || s[i + j] != s[i]) {
                    for (int k = 1; k <= len; k++) {
                        if (i + j + k - 1 >= len || i - k < 0 || s[i - k] != s[i + j + k - 1]) {
                            if (maxlen < j + 2 * k - 2) {
                                start = i - k + 1;
                                maxlen = j + 2 * k - 2;
                            }
                            break;
                        }
                    }
                    i += j;
                    break;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};