class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n);
        int maxStep = 0;
        int currStep = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int curr = i;
                int currStep = 0;
                while (!visited[curr]) {
                    ++currStep;
                    visited[curr] = true;
                    curr = nums[curr];
                }
                maxStep = max(maxStep, currStep);
            }
        }
        return maxStep;
    }
};