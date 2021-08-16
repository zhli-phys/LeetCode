class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        int prevHeight = 0;
        vector<int> ans;
        for (int i = n - 1; i >= 0; --i) {
            if (heights[i] > prevHeight) {
                ans.push_back(i);
                prevHeight = heights[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};