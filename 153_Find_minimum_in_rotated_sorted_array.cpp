class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return search(0, n - 1, nums);
    }
    
    int search(int left, int right, vector<int>& nums) {
        if (left == right)
            return nums[left];
        if (right == left + 1)
            return min(nums[left], nums[right]);
        int mid = (left + right) / 2;
        if (nums[mid] > nums[left])
            return min(nums[left], search(mid, right, nums));
        else
            return search(left, mid, nums);
    }
};