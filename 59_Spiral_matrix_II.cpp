class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int i = 0; 
        int j = 0;
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currDir = 0;
        for (int k = 0; k < n * n ; ++k) {
            ans[i][j] = k + 1;
            if (!isValid(i + dirs[currDir][0], j + dirs[currDir][1], ans))
                currDir = (currDir + 1) % 4;
            i += dirs[currDir][0];
            j += dirs[currDir][1];
        }
        return ans;
    }
    
    inline bool isValid(int i, int j, vector<vector<int>>& ans) {
        return i >= 0 && i < ans.size() && j >= 0 && j < ans.size() && ans[i][j] == 0;
    }
};