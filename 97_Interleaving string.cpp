//4 ms 66%; 6.7 MB 52%
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n = s3.size();
        if (n1 + n2 != n)
            return false;
        if (n == 0)
            return true;
        else if (n2 == 0)
            return s3 == s1;
        vector<vector<bool>> dp(n, vector<bool>(n2 + 1, false));
        dp[0][0] = (s3[0] == s1[0]);
        dp[0][1] = (s3[0] == s2[0]);
        for (int i = 1; i < n; ++i) 
            for (int j = 0; j <= n2; ++j) 
                dp[i][j] = ((j > 0 && dp[i-1][j-1] && s3[i] == s2[j-1]) 
                           || (dp[i-1][j] && j > i - n1 && s3[i] == s1[i-j]));
        return dp[n-1][n2];
    }
};










//Less space; 0 ms 100%; 6.1 MB 89%
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n = s3.size();
        if (n1 + n2 != n)
            return false;
        if (n == 0)
            return true;
        else if (n2 == 0)
            return s3 == s1;
        vector<bool> prev(n2 + 1, false);
        vector<bool> curr(n2 + 1, false);
        curr[0] = (s3[0] == s1[0]);
        curr[1] = (s3[0] == s2[0]);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= n2; ++j)
                prev[j] = curr[j];
            for (int j = 0; j <= n2; ++j) 
                curr[j] = ((j > 0 && prev[j-1] && s3[i] == s2[j-1]) 
                           || (prev[j] && j > i - n1 && s3[i] == s1[i-j]));
        }
        return curr[n2];
    }
};















//refined; 0 ms 100%; 6.3 MB 70%
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n = s3.size();
        if (n1 + n2 != n)
            return false;
        vector<bool> curr(n2 + 1, false);
        curr[0] = true;
        for (int j = 1; j <= n2; ++j) {
            if (s2[j-1] == s3[j-1])
                curr[j] = true;
            else
                break;
        }
        for (int i = 1; i <= n1; ++i) {
            curr[0] = (curr[0] && s1[i-1] == s3[i-1]);
            for (int j = 1; j <= n2; ++j) 
                curr[j] = ((curr[j-1] && s2[j-1] == s3[i+j-1]) 
                           || (curr[j] && s1[i-1] == s3[i+j-1]));
        }
        return curr[n2];
    }
};