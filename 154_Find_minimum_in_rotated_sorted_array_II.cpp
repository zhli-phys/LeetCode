class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(0, nums.size() - 1, nums);
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right])
                return nums[left];
            int mid = (left + right) / 2;
            if (nums[left] > nums[right]) {
                if (nums[mid] <= nums[right])
                    right = mid;
                else
                    left = mid + 1;
            }
            else {
                if (nums[mid] < nums[right])
                    right = mid;
                else if (nums[mid] > nums[left])
                    left = mid + 1;
                else {
                    
                }
            }
        }
    }
    
    int findMin(int left, int right, vector<int>& nums) {
        if (left == right || nums[left] < nums[right])
            return nums[left];
        int mid = (left + right) / 2;
        if (nums[left] > nums[right]) {
            if (nums[mid] <= nums[right])
                return findMin(left, mid, nums);
            else
                return findMin(mid + 1, right, nums);
        }
        else {
            if (nums[mid] < nums[right])
                return findMin(left, mid, nums);
            else if (nums[mid] > nums[left])
                return findMin(mid + 1, right, nums);
            else 
                return min(findMin(left, mid, nums), findMin(mid + 1, right, nums));
        }
    }
};