class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        while (right > left) {
            int middle = (left + right) / 2;
            if (duplicate(nums, middle))
                right = middle;
            else
                left = middle + 1;
        }
        return left;
    }
    
    bool duplicate(vector<int>& nums, int n) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= n)
                count++;
        }
        return count > n;
    }
};





class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int pos = 0;
        while (slow != pos) {
            slow = nums[slow];
            pos = nums[pos];
        }
        return pos;
    }
};