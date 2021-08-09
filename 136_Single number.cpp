class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sol = nums[0];
        for (int i = 1; i < nums.size(); i++)
            sol = sol^nums[i];
        return sol;
    }
};