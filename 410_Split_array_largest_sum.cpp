class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while (left < right) {
            int mid = (left + right) / 2;
            if (bins(mid, nums) <= m)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    
    int bins(int bound, vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        for (int num : nums) {
            curr += num;
            if (curr > bound) {
                curr = num;
                ++ans;
            }
        }
        if (curr > 0)
            ++ans;
        return ans;
    }
};