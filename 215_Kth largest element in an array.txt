class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, k - 1, 0, nums.size() - 1);
    }
    
    int find(vector<int>& nums, int k, int left, int right) {
        if (left == right)
            return nums[left];
        if (right == left + 1) {
            if (k == right)
                return min(nums[left], nums[right]);
            else
                return max(nums[left], nums[right]);
        }
        int middle = (left + right) / 2;
        int three[3] = { nums[left], nums[middle], nums[right] };
        sort(three, three + 3);
        nums[left] = three[0];
        nums[middle] = three[1];
        nums[right] = three[2];
        int pivot = nums[middle];
        int left_pos = left;
        int right_pos = right;
        while (left_pos < right_pos) {
            swap(nums[left_pos], nums[right_pos]);
            left_pos++;
            right_pos--;
            while (nums[left_pos] > pivot)
                left_pos++;
            while (nums[right_pos] < pivot)
                right_pos--;
        }
        if (left_pos == right_pos) {
            if (k == left_pos)
                return pivot;
            else if (k < left_pos)
                return find(nums, k, left, left_pos - 1);
            else
                return find(nums, k, right_pos + 1, right);
        }
        else {
            if (k < left_pos)
                return find(nums, k, left, left_pos - 1);
            else
                return find(nums, k, right_pos + 1, right);
        }
    }
};