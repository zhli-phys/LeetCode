class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(0, nums.size() - 1, nums, target);
    }
    
    bool search(int left, int right, vector<int>& nums, int target) {
        if (left > right)
            return false;
        int mid = (left + right) / 2;
        if (nums[mid] == target || nums[left] == target || nums[right] == target)
            return true;
        if (nums[left] == nums[right]) 
            return search(left + 1, right - 1, nums, target);
        else if (nums[left] > nums[right]) {
            if (nums[mid] < nums[left]) {
                if (target > nums[mid] && target < nums[right])
                    return search(mid + 1, right - 1, nums, target);
                else
                    return search(left + 1, mid - 1, nums, target);
            }
            else {
                if (target > nums[left] && target < nums[mid])
                    return search(left + 1, mid - 1, nums, target);
                else
                    return search(mid + 1, right - 1, nums, target);
            }
        }
        else {
            if (nums[mid] < target)
                return search(mid + 1, right - 1, nums, target);
            else
                return search(left + 1, mid - 1, nums, target);
        }
    }
};