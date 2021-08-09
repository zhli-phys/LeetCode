class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> ways(n + 1, -1);
        ways[n] = 1;
        return helper(s, 0, ways);
    }
    
    int helper(string& s, int start, vector<int>& ways) {
        if (ways[start] >= 0)
            return ways[start];
        int ans = 0;
        int n = s.size();
        if (s[start] == '0') {
            ways[start] = 0;
            return 0;
        }
        ans = ans + helper(s, start + 1, ways);
        if (start < n - 1 && (s[start] < '2' || (s[start] == '2' && s[start + 1] <= '6')))
            ans = ans + helper(s, start + 2, ways);
        ways[start] = ans;
        return ans;
    }
};