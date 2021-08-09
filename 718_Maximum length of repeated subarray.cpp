//dynamical programing; O(n1 * n2) 472 ms 10%; O(n1 * n2) 109 MB 30%
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        int len = 0;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    len = max(len, dp[i][j]);
                }                    
                else
                    dp[i][j] = 0;
            }
        }
        return len;
    }
};









//dynamical programming; O(n1 * n2) 384 ms 15%; O(n2) 11.8 MB 92%
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> curr(n2 + 1);
        vector<int> prev(n2 + 1);
        int len = 0;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (nums1[i-1] == nums2[j-1]) {
                    curr[j] = prev[j-1] + 1;
                    len = max(len, curr[j]);
                }                    
                else
                    curr[j] = 0;
            }
            for (int j = 1; j <= n2; ++j)
                prev[j] = curr[j];
        }
        return len;
    }
};