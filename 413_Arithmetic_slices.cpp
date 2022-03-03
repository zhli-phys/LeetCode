class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        int ans = 0;
        int currDiff = nums[1] - nums[0];
        int currLen = 2;
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i-1] == currDiff) {
                ++currLen;
            }
            else {
                ans += (currLen - 1) * (currLen - 2) / 2;
                currLen = 2;
                currDiff = nums[i] - nums[i-1];
            }
        }
        ans += (currLen - 1) * (currLen - 2) / 2;
        return ans;
    }
};