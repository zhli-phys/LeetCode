//O(m^2 n log n) 1056 ms 36%; O(n * m) 293.5 MB 20%
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        vector<vector<int>> presum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) 
            for (int j = 1; j <= n; ++j)
                presum[i][j] = matrix[i-1][j-1] + presum[i-1][j];
        for (int up = 0; up < m; ++up) {
            for (int down = up + 1; down <= m; ++down) {
                set<int> st;
                st.insert(0);
                int curr = 0;
                for (int j = 1; j <= n; ++j) {
                    curr += presum[down][j] - presum[up][j];
                    auto it = st.lower_bound(curr - k);
                    if (it != st.end() && curr - *it > ans)
                        ans = curr - *it;
                    st.insert(curr);
                }
            }
        }
        return ans;
    }
};