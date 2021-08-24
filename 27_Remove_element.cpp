class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};








class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            if (nums[left] != val) {
                ++ans;
                ++left;
            }
            else {
                while (left < right && nums[right] == val)
                    --right;
                if (left < right) {
                    swap(nums[left], nums[right]);
                    ++ans;
                    ++left;
                    --right;
                }
                else
                    break;
            }
        }
        return ans;
    }
};