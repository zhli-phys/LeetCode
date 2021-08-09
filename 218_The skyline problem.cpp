class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        int len = 0;
        for (int i = 0; i < n; i++)
            len = max(len, buildings[i][1]);
        
        vector<int> heights(len, 0);
        for (int i = 0; i < n; i++) {
            for (int j = buildings[i][0]; j < buildings[i][1]; j++)
                heights[j] = max(heights[j], buildings[i][2]);
        }
        vector<vector<int>> ans;
        int curr = 0;
        for (int j = 0; j < len; j++) {
            if (heights[j] != curr) {
                vector<int> bi(2);
                bi[0] = j;
                bi[1] = heights[j];
                curr = heights[j];
                ans.push_back(bi);
            }
        }
        if (len > 0) {
            vector<int> bi(2);
            bi[0] = len;
            bi[1] = 0;
            ans.push_back(bi);
        }
        return ans;
    }
};