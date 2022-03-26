class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(0, nums.size() - 1, nums, target);
    }
    
    int search(int left, int right, vector<int>& nums, int target) {
        if (left > right)
            return -1;
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return search(left, mid - 1, nums, target);
        else 
            return search(mid + 1, right, nums, target);
    }
};