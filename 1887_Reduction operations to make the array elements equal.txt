class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int curr = nums[0];
        int count = 0;
        int step = 0;
        for (int num : nums) {
            if (num == curr) {
                count += step;
            }
            else {
                ++step;
                count += step;
                curr = num;
            }
        }
        return count;
    }
};