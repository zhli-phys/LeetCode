class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size()-1);
    }
    
    int search(vector<int>& nums, int target, int left, int right) {
        if (left > right)
            return -1;
        int l = nums[left];
        int r = nums[right];
        if (l == target) 
            return left;
        if (r == target)
            return right;
        int middle = (left + right) / 2;
        int m = nums[middle];
        if (m == target)
            return middle;
        if (l < m && m < r) {
            if (target > m)
                return search(nums, target, middle + 1, right);
            else
                return search(nums, target, left, middle -1);
        }
        if (r < l && l < m) {
            if (target > m || target < r)
                return search(nums, target, middle + 1, right);
            else
                return search(nums, target, left, middle -1);
        }
        else {
            if (m < target && target < r)
                return search(nums, target, middle + 1, right);
            else 
                return search(nums, target, left, middle -1);
        }
    }
};