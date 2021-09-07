class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int preMax = 0;
        int preMin = 0;
        int currSum = 0;
        int currMax = INT_MIN;
        int currMin = INT_MAX;
        for (int num : nums) {
            currMin = min(currMin, currSum - preMax);
            currSum += num;
            currMax = max(currMax, currSum - preMin);
            preMax = max(preMax, currSum);
            preMin = min(preMin, currSum);
        }
        return max(currMax, currSum - currMin);
    }
};