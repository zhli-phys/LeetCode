\\Time limit exceeded
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            for (int j = 1; j <= len - i; j++) {
                string p = s.substr(i, j);
                reverse(p.begin(), p.end());
                if (p == s.substr(i, j))
                    ans++;
            }
        }
        return ans;
    }
};






class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            int k = min(i + 1, len - i);
            for (int j = 0; j < k; j++) {
                if (s[i - j] == s[i + j])
                    ans++;
                else
                    break;
            }
        }
        for (int i = 1; i < len; i++) {
            int k = min(i, len - i);
            for (int j = 1; j <= k; j++) {
                if (s[i - j] == s[i + j - 1])
                    ans++;
                else
                    break;
            }
        }
        return ans;
    }
};