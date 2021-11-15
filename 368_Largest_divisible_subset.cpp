class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<unordered_set<int>> edges(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] % nums[i] == 0)
                    edges[i].insert(j);
            }
        }
        vector<int> dp(n, -1);
        vector<int> next(n, -1);
        int head = 0;
        int len = 1;
        for (int i = 0; i < n; ++i) {
            int currLen = length(i, edges, dp, next);
            if (currLen > len) {
                head = i;
                len = currLen;
            }
        }
        vector<int> ans;
        while (head >= 0) {
            ans.push_back(nums[head]);
            head = next[head];
        }
        return ans;
    }
    
    int length(int i, vector<unordered_set<int>>& edges, vector<int>& dp, vector<int>& next) {
        if (dp[i] > 0)
            return dp[i];
        int maxLen = 0;
        for (int j : edges[i]) {
            int currLen = length(j, edges, dp, next);
            if (currLen > maxLen) {
                maxLen = currLen;
                next[i] = j;
            }
        }
        dp[i] = maxLen + 1;
        return dp[i];
    }
};