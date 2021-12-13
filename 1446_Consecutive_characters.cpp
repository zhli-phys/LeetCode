class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        int curr = 1;
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1])
                ++curr;
            else {
                ans = max(curr, ans);
                curr = 1;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};