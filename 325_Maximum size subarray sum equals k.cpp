class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int maxLen = 0;
        unordered_map<int, int> preSum;
        preSum[0] = -1;
        int currSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            currSum += nums[i];
            auto it = preSum.find(currSum - k);
            if (it != preSum.end()) 
                maxLen = max(maxLen, i - it->second);
            if (preSum.find(currSum) == preSum.end())
                preSum[currSum] = i;
        }
        return maxLen;
    }
};