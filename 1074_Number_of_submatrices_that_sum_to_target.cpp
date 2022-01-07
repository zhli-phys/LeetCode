class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> preSum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) 
            for (int j = 1; j <= n; ++j) 
                preSum[i][j] = matrix[i-1][j-1] + preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1];
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int k = i + 1; k <= m; ++k) {
                unordered_map<int, int> count;
                ++count[0];
                for (int j = 1; j <= n; ++j) {
                    int curr = preSum[k][j] - preSum[i][j];
                    if (count.find(curr - target) != count.end())
                        ans += count[curr - target];
                    ++count[curr];
                }
            }
        }
        return ans;
    }
};