class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre_count = 0;
        int curr_count = 1;
        int ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1])
                ++curr_count;
            else {
                ans += min(pre_count, curr_count);
                pre_count = curr_count;
                curr_count = 1;
            }
        }
        ans += min(pre_count, curr_count);
        return ans;
    }
};