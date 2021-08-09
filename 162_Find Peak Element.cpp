class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return findPeakElement(0, n, nums);
    }
    
    int findPeakElement(int left, int right , vector<int>& nums) {
        if (left == right-1)
            return left;
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid-1])
            return findPeakElement(mid, right, nums);
        else 
            return findPeakElement(left, mid, nums);
    }
};