class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        bool all_negative = (nums[0] < 0);
        int negative_sum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                all_negative = false;
                break;
            }
            else
                negative_sum = max(negative_sum, nums[i]);
        }
        if (all_negative)
            return negative_sum;
        int maxsum = 0;
        int current_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            current_sum = max(current_sum + nums[i], 0);
            maxsum = max(maxsum, current_sum);
        }
        return maxsum;
    }
};



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int current_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            current_sum = max(current_sum + nums[i], nums[i]);
            maxsum = max(maxsum, current_sum);
        }
        return maxsum;
    }
};



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size());
    }
    
    int maxSubArray(vector<int>& nums, int left, int right) {
        if (left == right -1)
            return nums[left];
        int middle = (left + right) / 2;
        int maxsum = nums[middle];
        int current = nums[middle];
        for (int i = middle + 1; i < right; i++) {
            current += nums[i];
            maxsum = max(maxsum, current);
        }
        current = maxsum;
        for (int i = middle - 1; i >= left; i--) {
            current += nums[i];
            maxsum = max(maxsum, current);
        }
        int sums[3] = { maxsum, maxSubArray(nums, left, middle), maxSubArray(nums, middle, right) };
        return *max_element(sums, sums + 3);
    }
};